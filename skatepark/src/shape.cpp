#include "shape.h"

namespace OpenGL
{
	Shape::Shape(
		glm::vec3 position_value,
		glm::vec3 rotate_value,
		glm::vec3 color_value,
		float scale_value,
		const char* texture,
		float shyniness_value,
		bool shading,
		const char* vertex,
		const char* fragment
	) : ID(0), VBO(0), IBO(0), VAO(0), TEX(0),
		TEXTURE(texture), VERTEX(vertex), FRAGMENT(fragment),
		position(position_value), origin_position(position_value),
		rotate(rotate_value), origin_rotate(rotate_value),
		color(color_value), texScale(1.0f), shininess(shyniness_value), shading(shading),
		scale(scale_value), origin_scale(scale_value) {}

	Shape::~Shape() {}

	void Shape::Init() {
		if (strcmp(TEXTURE, "empty") != 0) TEX = Loader::BMP(TEXTURE);
		InitShader();
		InitVBO();
		if (!indices.empty()) InitIBO();
		InitVAO();
	}

	void Shape::InitShader()
	{
		char* vertexshader = glsl::readFile(VERTEX);
		GLuint vsh_id = glsl::makeVertexShader(vertexshader);
		delete[] vertexshader;

		char* fragshader = glsl::readFile(FRAGMENT);
		GLuint fsh_id = glsl::makeFragmentShader(fragshader);
		delete[] fragshader;

		ID = glsl::makeShaderProgram(vsh_id, fsh_id);
	}

	void Shape::InitVBO()
	{
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Format3D), vertices.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Shape::InitIBO()
	{
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), indices.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Shape::InitVAO()
	{
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Format3D), (void*)offsetof(Format3D, position));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Format3D), (void*)offsetof(Format3D, normals));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Format3D), (void*)offsetof(Format3D, uvs));
		glEnableVertexAttribArray(2);

		if (!indices.empty())
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		if (!indices.empty())
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Shape::Update(glm::mat4 projection_matrix, glm::mat4 view_matrix)
	{
		projection = projection_matrix;
		view = view_matrix;
		model = (glm::translate(glm::mat4(1.0f), glm::vec3(position)) *
				(glm::rotate(glm::mat4(1.0f), glm::radians(rotate.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
				(glm::rotate(glm::mat4(1.0f), glm::radians(rotate.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
				 glm::rotate(glm::mat4(1.0f), glm::radians(rotate.z), glm::vec3(0.0f, 0.0f, 1.0f)))) *
				 glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, scale)));
	}

	void Shape::Reset()
	{
		position = origin_position;
		rotate = origin_rotate;
		scale = origin_scale;

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		for (size_t i = 0; i < (!indices.empty() ? indices.size() : vertices.size()); ++i) {
			glm::vec3 normals = vertices[i].normals;
			size_t colorOffset = i * sizeof(OpenGL::Format3D) + offsetof(OpenGL::Format3D, normals);
			glBufferSubData(GL_ARRAY_BUFFER, colorOffset, sizeof(glm::vec3), &normals);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Shape::Render(glm::vec3 camera, glm::vec3 sun) {
		glUseProgram(ID);

		glBindVertexArray(VAO);
		glUniformMatrix4fv(glGetUniformLocation(ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(glGetUniformLocation(ID, "color"), 1, glm::value_ptr(color));
		glUniform3fv(glGetUniformLocation(ID, "camera"), 1, glm::value_ptr(camera));
		glUniform3fv(glGetUniformLocation(ID, "sun"), 1, glm::value_ptr(sun));
		glUniform1i(glGetUniformLocation(ID, "hasTexture"), TEX != 0);
		glUniform1f(glGetUniformLocation(ID, "shininess"), shininess);
		glUniform1i(glGetUniformLocation(ID, "shading"), shading ? 1 : 0);

		if (TEX != 0) {
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, TEX);
			glUniform2f(glGetUniformLocation(ID, "texScale"), texScale, texScale);
		}

		if (!indices.empty())
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
			glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		else
			glDrawArrays(GL_TRIANGLES, 0, vertices.size());

		glBindVertexArray(0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		if (TEX != 0)
			glBindTexture(GL_TEXTURE_2D, 0);
		if (!indices.empty())
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glUseProgram(ZERO_ID);
	}
}