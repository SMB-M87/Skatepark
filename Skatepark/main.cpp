#include <GL/glew.h>
#include <GL/freeglut.h>

#include "skybox.h"
#include "skatepark.h"
#include "skateboard.h"

using namespace std;

void InitGlutGlew(int argc, char** argv);
void Reset();
void Update();
void Render();
void Reshape(int width, int height);
void Timer(int value);
void SpecialKeyHandler(int key, int x, int y);
void SpecialKeyUpHandler(int key, int x, int y);
void KeyboardHandler(unsigned char key, int x, int y);
void KeyboardUpHandler(unsigned char key, int x, int y);
void MouseMoveHandler(int x, int y);
void MouseHandler(int button, int state, int x, int y);
void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

const int TIMER = 1;

// Window
int width = 800, height = 600;

// Keyboard
bool FORWARD = false, BACKWARD = false, LEFT = false, RIGHT = false, UP = false, DOWN = false, ROTATE_UP = false, ROTATE_DOWN = false, ROTATE_LEFT = false, ROTATE_RIGHT = false;

// Mouse
int X = 0, Y = 0;
float mouse_sensivity = 0.05f;

// Object's
OpenGL::Skybox skybox{};
OpenGL::Skatepark skatepark{};
OpenGL::Skateboard skate{ { -3.825f, 0.09f, -1.0f }, { 0.0f, 180.0f, -25.0f }, { 0.5f, 0.5f, 0.5f }, 0.055f, "Texture/Graffiti/graffiti1.bmp", 65.0f};
OpenGL::Skateboard skateboard{ { -4.5f, -0.725f, 4.25f }, { 0.0f, 180.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 0.055f, "Texture/Graffiti/graffiti.bmp", 65.0f};

// Projection
glm::mat4 projection;
float field_of_view = 45.0f;
glm::vec3 aspect_ratio = { static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f };

// View
glm::mat4 view;
glm::vec3 camera_target = glm::vec3(13.0f, -4.0f, 18.0f);
glm::vec3 camera_position = glm::vec3(-4.5f, 1.5f, -5.5f);
glm::quat camera_orientation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));

glm::vec3 walking_position = glm::vec3(-4.5f, 1.5f, -5.5f);
glm::vec3 walking_target = camera_target;
glm::quat walking_orientation = camera_orientation;

glm::vec3 droning_position = camera_position;
glm::vec3 droning_target = camera_target;
glm::quat droning_orientation = camera_orientation;

bool walk = true;
float camera_speed = 0.1f;
glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 camera_origin_target = glm::vec3(13.0f, -4.0f, 18.0f);
glm::quat camera_origin_orientation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
glm::vec3 walk_position = glm::vec3(-4.5f, 1.5f, -5.5f);
glm::vec3 drone_position = glm::vec3(-15.5f, 13.0f, -13.5f);

// Sun & Orbit
float angle = 0.0f;
float radiusX = 30.0f;
float radiusY = 15.0f;
float radiusZ = 30.0f;
float centerX = 0.0f;
float centerY = 25.0f;
float centerZ = 10.0f;
OpenGL::Sphere sun{ false, 180, 90, 360, 90, { 0.0f, 0.0f, 0.0f }, { 20.0, 50.0f, 30.0f }, {0.0f, 0.0f, 0.0f}, {0.5f, 0.5f, 0.5f}, 2.5f, "Texture/sun.bmp", 128.0f, false};
float torusOrbitRadius = 10.0f;
float torusOrbitAngle = 0.0f;
OpenGL::Torus torus{ 360, 90, 360, 90, 1.0f, 0.5f, { 0.0f, 0.0f, 0.0f }, { sun.position.x + 5.0f, sun.position.y, sun.position.z + 6.0f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 1.0f, "Texture/metallic.bmp", 128.0f };
float cylOrbitRadius = 6.0f;
float cylOrbitAngle = 0.0f;
OpenGL::Cylinder cyl{ false, 360, 90, 1.0f, 2.0f, { sun.position.x, sun.position.y + 3.0f, sun.position.z + 4.0f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 0.5f, "Texture/Graffiti/graffiti.bmp", 69.0f };
float cubeOrbitRadius = 4.0f;
float cubeOrbitAngle = 0.0f;
OpenGL::Cuboid cube{ { -1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f }, { -1.0f,  1.0f, -1.0f }, { 1.0f,  1.0f, -1.0f }, { -1.0f, -1.0f,  1.0f }, { 1.0f, -1.0f,  1.0f }, { -1.0f, -1.0f, -1.0f }, { 1.0f, -1.0f, -1.0f }, { cyl.position.x, cyl.position.y + 3.5f, cyl.position.z + 2.0f }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 0.4f, "Texture/Graffiti/graffiti1.bmp", "shader.vert", "shader.frag", 63.0f };
float prismOrbitRadius = 3.0f;
float prismOrbitAngle = 0.0f;
OpenGL::Prism prism{ 1.0f, 1.0f, 1.0f, 0.0f, -1.0f, {  cube.position.x + 1.5f, cube.position.y + 2.5f, cube.position.z }, { 0.0f, 0.0f, 0.0f }, { 0.5f, 0.5f, 0.5f }, 0.25f, "Texture/Graffiti/graffiti3.bmp", 32.0f };
bool regular = true;

int main(int argc, char** argv)
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	InitGlutGlew(argc, argv);
	Reset();
	skybox.Init();
	skybox.InitCubemap();
	skatepark.Init();
	sun.Init();
	torus.Init();
	cyl.Init();
	cube.Init();
	prism.Init();
	skate.Init();
	skateboard.Init();
	glutMainLoop();
	return 0;
}

void InitGlutGlew(int argc, char** argv)
{
	// View
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);

	// Keyboard
	glutKeyboardFunc(KeyboardHandler);
	glutKeyboardUpFunc(KeyboardUpHandler);
	glutSpecialFunc(SpecialKeyHandler);
	glutSpecialUpFunc(SpecialKeyUpHandler);

	// Mouse
	glutMouseFunc(MouseHandler);
	glutMotionFunc(MouseMoveHandler);

	// Other
	glutTimerFunc(TIMER, Timer, 0);
	glEnable(GL_DEPTH_TEST);
	glewInit();

	// Debug
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DEBUG_TYPE_ERROR, GL_DONT_CARE, 0, NULL, GL_TRUE);
	glDebugMessageCallback(MessageCallback, nullptr);
}

// Debug
void GLAPIENTRY MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}

void Update() {
	if (FORWARD)
	{
		glm::vec3 movement = glm::normalize(camera_target - camera_position) * camera_speed;
		if (walk && camera_position.y + camera_speed < 2.0f && camera_position.y - camera_speed > 0.3f) {
			camera_position += movement;
			camera_target += movement;
		}
		else if (!walk) {
			camera_position += movement;
			camera_target += movement;
		}
		else {
			movement.y = 0;
			camera_position += movement;
			camera_target += movement;
		}
	}
	if (BACKWARD)
	{
		glm::vec3 movement = glm::normalize(camera_target - camera_position) * camera_speed;
		if (walk && camera_position.y + camera_speed < 2.0f && camera_position.y - camera_speed > 0.3f) {
			camera_position -= movement;
			camera_target -= movement;
		}
		else if (!walk) {
			camera_position -= movement;
			camera_target -= movement;
		}
		else {
			movement.y = 0;
			camera_position -= movement;
			camera_target -= movement;
		}
	}
	if (LEFT)
	{
		glm::vec3 left = glm::normalize(glm::cross(camera_target - camera_position, camera_up));
		camera_position -= camera_speed * left;
		camera_target -= camera_speed * left;
	}
	if (RIGHT)
	{
		glm::vec3 right = glm::normalize(glm::cross(camera_target - camera_position, camera_up));
		camera_position += camera_speed * right;
		camera_target += camera_speed * right;
	}
	if (UP)
	{
		glm::vec3 movement = camera_up * camera_speed;
		if (walk && camera_position.y + camera_speed < 2.0f) {
			camera_position += movement;
			camera_target += movement;
		}
		else if (!walk) {
			camera_position += movement;
			camera_target += movement;
		}
		else {
			movement.y = 0;
			camera_position += movement;
			camera_target += movement;
		}
	}
	if (DOWN)
	{
		glm::vec3 movement = camera_up * camera_speed;
		if (walk && camera_position.y - camera_speed > 0.3f) {
			camera_position -= movement;
			camera_target -= movement;
		}
		else if (!walk) {
			camera_position -= movement;
			camera_target -= movement;
		}
		else {
			movement.y = 0;
			camera_position -= movement;
			camera_target -= movement;
		}
	}
	if (ROTATE_UP) {
		glm::quat rotation = glm::angleAxis((-camera_speed * 0.15f), glm::vec3(1, 0, 0));
		glm::vec3 direction = glm::normalize(camera_target - camera_position);
		direction = rotation * direction;
		camera_target = camera_position + direction;
	}
	if (ROTATE_DOWN) {
		glm::quat rotation = glm::angleAxis((camera_speed * 0.15f), glm::vec3(1, 0, 0));
		glm::vec3 direction = glm::normalize(camera_target - camera_position);
		direction = rotation * direction;
		camera_target = camera_position + direction;
	}
	if (ROTATE_LEFT) {
		glm::quat rotation = glm::angleAxis((camera_speed * 0.3f), glm::vec3(0, 1, 0));
		glm::vec3 direction = glm::normalize(camera_target - camera_position);
		direction = rotation * direction;
		camera_target = camera_position + direction;
	}
	if (ROTATE_RIGHT) {
		glm::quat rotation = glm::angleAxis((-camera_speed * 0.3f), glm::vec3(0, 1, 0));
		glm::vec3 direction = glm::normalize(camera_target - camera_position);
		direction = rotation * direction;
		camera_target = camera_position + direction;
	}

	projection = glm::perspective(glm::radians(field_of_view), aspect_ratio.x, aspect_ratio.y, aspect_ratio.z);
	view = glm::lookAt(camera_position, camera_target, camera_up) * glm::mat4_cast(camera_orientation);

	skybox.Update(projection, view);
	skatepark.Update(projection, view);
	sun.Update(projection, view);
	torus.Update(projection, view);
	cyl.Update(projection, view);
	cube.Update(projection, view);
	prism.Update(projection, view);
	skate.Update(projection, view);
	skateboard.Update(projection, view);
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Update();

	static const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	glClearBufferfv(GL_COLOR, 0, black);

	skybox.Render(camera_position, sun.position);
	skatepark.Render(camera_position, sun.position);
	sun.Render(camera_position, sun.position);
	torus.Render(camera_position, sun.position);
	cyl.Render(camera_position, sun.position);
	cube.Render(camera_position, sun.position);
	prism.Render(camera_position, sun.position);
	skate.Render(camera_position, sun.position);
	skateboard.Render(camera_position, sun.position);

	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	width = w;
	height = h;
	aspect_ratio.x = (float)w / (float)h;
	glutPostRedisplay();
}

void Reset()
{
	field_of_view = 45.0f;
	camera_target = camera_origin_target;
	camera_position = walk_position;
	camera_orientation = camera_origin_orientation;
	walking_position = walk_position;
	walking_target = camera_origin_target;
	walking_orientation = camera_origin_orientation;
	droning_position = drone_position;
	droning_target = camera_origin_target;
	droning_orientation = camera_origin_orientation;
	walk = true;
}

void KeyboardHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		FORWARD = true;
		break;
	case 's':
	case 'S':
		BACKWARD = true;
		break;

	case 'a':
	case 'A':
		LEFT = true;
		break;

	case 'j':
	case 'J':
		ROTATE_LEFT = true;
		break;

	case 'd':
	case 'D':
		RIGHT = true;
		break;

	case 'l':
	case 'L':
		ROTATE_RIGHT = true;
		break;

	case 'e':
	case 'E':
		UP = true;
		break;

	case 'i':
	case 'I':
		ROTATE_UP = true;
		break;

	case 'q':
	case 'Q':
		DOWN = true;
		break;

	case 'k':
	case 'K':
		ROTATE_DOWN = true;
		break;

	case 'v':
	case 'V':
	{
		if (walk) {
			walking_position = camera_position;
			walking_target = camera_target;
			walking_orientation = camera_orientation;
			camera_position = droning_position;
			camera_target = droning_target;
			camera_orientation = droning_orientation;
		}
		else {
			droning_position = camera_position;
			droning_target = camera_target;
			droning_orientation = camera_orientation;
			camera_position = walking_position;
			camera_target = walking_target;
			camera_orientation = walking_orientation;
		}
		walk = !walk;
		break;
	}

	case 'c':
	case 'C':
		Reset();
		break;

	case 27:
		glutExit();
		break;
	}
	glutPostRedisplay();
}

void KeyboardUpHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		FORWARD = false;
		break;
	case 's':
	case 'S':
		BACKWARD = false;
		break;

	case 'a':
	case 'A':
		LEFT = false;
		break;

	case 'j':
	case 'J':
		ROTATE_LEFT = false;
		break;

	case 'd':
	case 'D':
		RIGHT = false;
		break;

	case 'l':
	case 'L':
		ROTATE_RIGHT = false;
		break;

	case 'e':
	case 'E':
		UP = false;
		break;

	case 'i':
	case 'I':
		ROTATE_UP = false;
		break;

	case 'q':
	case 'Q':
		DOWN = false;
		break;

	case 'k':
	case 'K':
		ROTATE_DOWN = false;
		break;
	}
	glutPostRedisplay();
}

void SpecialKeyHandler(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		FORWARD = true;
		break;
	case GLUT_KEY_DOWN:
		BACKWARD = true;
		break;

	case GLUT_KEY_LEFT:
		LEFT = true;
		break;
	case GLUT_KEY_RIGHT:
		RIGHT = true;
		break;

	case GLUT_KEY_PAGE_UP:
		UP = true;
		break;
	case GLUT_KEY_PAGE_DOWN:
		DOWN = true;
		break;
	}
	glutPostRedisplay();
}

void SpecialKeyUpHandler(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		FORWARD = false;
		break;
	case GLUT_KEY_DOWN:
		BACKWARD = false;
		break;

	case GLUT_KEY_LEFT:
		LEFT = false;
		break;
	case GLUT_KEY_RIGHT:
		RIGHT = false;
		break;

	case GLUT_KEY_PAGE_UP:
		UP = false;
		break;
	case GLUT_KEY_PAGE_DOWN:
		DOWN = false;
		break;
	}
	glutPostRedisplay();
}

void MouseHandler(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		X = x, Y = y;

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		X = x, Y = y;
}

void MouseMoveHandler(int x, int y)
{
	int delta_x = x - X;
	int delta_y = y - Y;

	float angle_x = -static_cast<float>(delta_y) * mouse_sensivity;
	float angle_y = static_cast<float>(delta_x) * mouse_sensivity;

	float current_pitch = glm::degrees(asin((camera_target.y - camera_position.y) / glm::length(camera_target - camera_position)));
	float current_yaw = glm::degrees(atan2(camera_target.z - camera_position.z, camera_target.x - camera_position.x));

	float new_pitch = glm::clamp(current_pitch + angle_x, -89.0f, 89.0f); // Gimbal Lock
	float new_yaw = current_yaw + angle_y;

	float new_pitch_rad = glm::radians(new_pitch);
	float new_yaw_rad = glm::radians(new_yaw);

	glm::vec3 new_target_position;
	new_target_position.x = camera_position.x + cos(new_pitch_rad) * cos(new_yaw_rad);
	new_target_position.y = camera_position.y + sin(new_pitch_rad);
	new_target_position.z = camera_position.z + cos(new_pitch_rad) * sin(new_yaw_rad);

	camera_target = new_target_position;

	X = x;
	Y = y;

	glutPostRedisplay();
}

void Timer(int value)
{
	sun.position.x = centerX + sin(angle) * radiusX;
	sun.position.y = centerY + sin(angle) * radiusY;
	sun.position.z = centerZ + cos(angle) * radiusZ;
	angle += 0.001f;
	if (angle > 2 * 3.14f) angle = 0.0f;
	sun.rotate += glm::vec3(1.3, -1.69, -0.3);

	torusOrbitAngle += 0.01f;
	torus.position.x = sun.position.x + cos(torusOrbitAngle) * torusOrbitRadius;
	torus.position.y = sun.position.y;
	torus.position.z = sun.position.z + sin(torusOrbitAngle) * torusOrbitRadius;
	torus.rotate += glm::vec3(1.3, -1.69, -0.3);

	cylOrbitAngle += 0.015f;
	cyl.position.x = sun.position.x;
	cyl.position.y = sun.position.y + cos(cylOrbitAngle) * cylOrbitRadius;
	cyl.position.z = sun.position.z + sin(cylOrbitAngle) * cylOrbitRadius;
	cyl.rotate += glm::vec3(-1.3, 1.69, 0.3);

	cubeOrbitAngle += 0.0069f;
	cube.position.x = sun.position.x + sin(cubeOrbitAngle) * cubeOrbitRadius;
	cube.position.y = sun.position.y;
	cube.position.z = sun.position.z + cos(cubeOrbitAngle) * cubeOrbitRadius;
	cube.rotate += glm::vec3(1.0);

	prismOrbitAngle += 0.0069f;
	prism.position.x = sun.position.x + cos(prismOrbitAngle) * prismOrbitRadius;
	prism.position.y = sun.position.y + sin(prismOrbitAngle) * prismOrbitRadius;
	prism.position.z = sun.position.z;
	prism.rotate += glm::vec3(1.0, 2.0, 0.0);

	skateboard.position.x += regular ? 0.01f : -0.01f;
	if (regular && skateboard.position.x >= -1.0f && skateboard.position.x < 0.0f) {
		skateboard.rotate.z -= 1.8f;
		skateboard.position.y += 0.005f;
	}
	else if (regular && skateboard.position.x >= 0.0f && skateboard.position.x < 1.0f) {
		skateboard.rotate.x += 1.8f;
		skateboard.position.y -= 0.005f;
	}
	else if (!regular && skateboard.position.x <= 1.0f && skateboard.position.x > 0.0f) {
		skateboard.rotate.z += 1.8f;
		skateboard.position.y += 0.005f;
	}
	else if (!regular && skateboard.position.x <= 0.0f && skateboard.position.x > -1.0f) {
		skateboard.rotate.x -= 1.8f;
		skateboard.position.y -= 0.005;
	}
	else if (skateboard.position.x >= 4.5f || skateboard.position.x <= -4.5f) {
		regular = !regular;
	}

	glutPostRedisplay();
	glutTimerFunc(TIMER, Timer, 0);
}