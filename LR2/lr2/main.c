#include <windows.h>
#include <gl/gl.h>
#include <math.h>
GLfloat rtri;

#pragma comment(lib, "opengl32.lib")

int xrot = 0;
int yrot = 0;
int zrot = 0;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

void containre() {
	glBegin(GL_QUADS); // перед
	glVertex3f(0, 0, 0);
	glVertex3f(3, 0, 0);
	glVertex3f(3, 1, 0);
	glVertex3f(0, 1, 0);
	glEnd();
	glBegin(GL_QUADS); // вверх
	glVertex3f(0, 1, 0);
	glVertex3f(3, 1, 0);
	glVertex3f(3, 1, -0.5);
	glVertex3f(0, 1, -0.5);
	glEnd();
	glBegin(GL_QUADS); // зад
	glVertex3f(0, 0, -0.5);
	glVertex3f(3, 0, -0.5);
	glVertex3f(3, 1, -0.5);
	glVertex3f(0, 1, -0.5);
	glEnd();
	glBegin(GL_QUADS); // низ
	glVertex3f(0, 0, 0);
	glVertex3f(3, 0, 0);
	glVertex3f(3, 0, -0.5);
	glVertex3f(0, 0, -0.5);
	glEnd();
	glBegin(GL_QUADS); // лево
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 1, -0.5);
	glVertex3f(0, 0, -0.5);
	glEnd();
	glBegin(GL_QUADS); //право
	glVertex3f(3, 0, 0);
	glVertex3f(3, 1, 0);
	glVertex3f(3, 1, -0.5);
	glVertex3f(3, 0, -0.5);
	glEnd();
}

void wheels_down() {
	float a = 3.14 * 2 / 10;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.2, -0.2, -0.5);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 2.2;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.5);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(2.2, -0.2, -0.5);
	glVertex3f(2.2, -0.2, -0.45);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 2.2;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.5);
		glVertex3f(x, y, -0.45);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.2, -0.2, -0.45);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 2.2;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.45);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.8, -0.2, -0.5);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.8;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.5);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(1.8, -0.2, -0.5);
	glVertex3f(1.8, -0.2, -0.45);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 1.8;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.5);
		glVertex3f(x, y, -0.45);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.8, -0.2, -0.45);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.8;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.45);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.4, -0.2, -0.5);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.5);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(1.4, -0.2, -0.5);
	glVertex3f(1.4, -0.2, -0.45);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 1.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.5);
		glVertex3f(x, y, -0.45);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.4, -0.2, -0.45);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.45);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.6, -0.2, -0.51);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 - 0.6;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.51);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.6, -0.2, -0.51);
	glVertex3f(-0.6, -0.2, -0.45);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 - 0.6;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.51);
		glVertex3f(x, y, -0.45);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.6, -0.2, -0.45);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 - 0.6;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.45);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.4, -0.2, -0.51);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 0.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.51);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.4, -0.2, -0.51);
	glVertex3f(0.4, -0.2, -0.45);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 0.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.51);
		glVertex3f(x, y, -0.45);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.4, -0.2, -0.45);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 0.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.45);
	}
	glEnd();
}

void wheels_up() {
	float a = 3.14 * 2 / 10;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.2, -0.2, 0);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 2.2;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(2.2, -0.2, 0);
	glVertex3f(2.2, -0.2, -0.05);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 2.2;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0);
		glVertex3f(x, y, -0.05);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.2, -0.2, -0.05);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 2.2;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.05);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.8, -0.2, 0);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.8;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(1.8, -0.2, 0);
	glVertex3f(1.8, -0.2, -0.05);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 1.8;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0);
		glVertex3f(x, y, -0.05);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.8, -0.2, -0.05);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.8;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.05);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.4, -0.2, 0);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(1.4, -0.2, 0);
	glVertex3f(1.4, -0.2, -0.05);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 1.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0);
		glVertex3f(x, y, -0.05);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1.4, -0.2, -0.05);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 1.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.05);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.6, -0.2, 0.01);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 - 0.6;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0.01);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.6, -0.2, 0.01);
	glVertex3f(-0.6, -0.2, -0.05);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 - 0.6;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0.01);
		glVertex3f(x, y, -0.05);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.6, -0.2, -0.05);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 - 0.6;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.05);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.4, -0.2, 0.01);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 0.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0.01);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.4, -0.2, 0.01);
	glVertex3f(0.4, -0.2, -0.05);
	for (int i = -1; i < 20; ++i) {
		float x = sin(a * i) * 0.2 + 0.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, 0.01);
		glVertex3f(x, y, -0.05);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.4, -0.2, -0.05);
	for (int i = -1; i < 10; ++i) {
		float x = sin(a * i) * 0.2 + 0.4;
		float y = cos(a * i) * 0.2 - 0.2;
		glVertex3f(x, y, -0.05);
	}
	glEnd();

}

void body_down() {
	glBegin(GL_QUADS); //перед
	glVertex3f(-0.2, 0, 0);
	glVertex3f(-0.2, -0.1, 0);
	glVertex3f(0.5, -0.1, 0);
	glVertex3f(0.5, 0, 0);
	glEnd();
	glBegin(GL_QUADS); // вверх
	glVertex3f(-0.2, 0, 0);
	glVertex3f(0.5, 0, 0);
	glVertex3f(0.5, 0, -0.5);
	glVertex3f(-0.2, 0, -0.5);
	glEnd();
	glBegin(GL_QUADS); //зад
	glVertex3f(-0.2, 0, -0.5);
	glVertex3f(-0.2, -0.1, -0.5);
	glVertex3f(0.5, -0.1, -0.5);
	glVertex3f(0.5, 0, -0.5);
	glEnd();
	glBegin(GL_QUADS); //низ
	glVertex3f(-0.2, -0.1, 0);
	glVertex3f(0.5, -0.1, 0);
	glVertex3f(0.5, -0.1, -0.5);
	glVertex3f(-0.2, -0.1, -0.5);
	glEnd();
	glBegin(GL_QUADS); //лево
	glVertex3f(-0.2, 0, 0);
	glVertex3f(-0.2, -0.1, 0);
	glVertex3f(-0.2, -0.1, -0.5);
	glVertex3f(-0.2, 0, -0.5);
	glEnd();
	glBegin(GL_QUADS); //право
	glVertex3f(0.5, 0, 0);
	glVertex3f(0.5, -0.1, 0);
	glVertex3f(0.5, -0.1, -0.5);
	glVertex3f(0.5, 0, -0.5);
	glEnd();
}

void body() {
	glBegin(GL_QUADS); // перед
	glVertex3f(-0.2, -0.1, 0);
	glVertex3f(-1, -0.1, 0);
	glVertex3f(-1, 0.9, 0);
	glVertex3f(-0.2, 1, 0);
	glEnd();
	glBegin(GL_QUADS); // вверх
	glVertex3f(-0.2, 1, 0);
	glVertex3f(-1, 0.9, 0);
	glVertex3f(-1, 0.9, -0.5);
	glVertex3f(-0.2, 1, -0.5);
	glEnd();
	glBegin(GL_QUADS); // зад
	glVertex3f(-0.2, -0.1, -0.5);
	glVertex3f(-1, -0.1, -0.5);
	glVertex3f(-1, 0.9, -0.5);
	glVertex3f(-0.2, 1, -0.5);
	glEnd();
	glBegin(GL_QUADS); // низ
	glVertex3f(-0.2, -0.1, 0);
	glVertex3f(-1, -0.1, 0);
	glVertex3f(-1, -0.1, -0.5);
	glVertex3f(-0.2, -0.1, -0.5);
	glEnd();
	glBegin(GL_QUADS); // лево
	glVertex3f(-1, -0.1, 0);
	glVertex3f(-1, 0.9, 0);
	glVertex3f(-1, 0.9, -0.5);
	glVertex3f(-1, -0.1, -0.5);
	glEnd();
	glBegin(GL_QUADS); // право
	glVertex3f(-0.2, -0.1, 0);
	glVertex3f(-0.2, 1, 0);
	glVertex3f(-0.2, 1, -0.5);
	glVertex3f(-0.2, -0.1, -0.5);
	glEnd();
}

void fari() {
	glBegin(GL_QUADS);
	glVertex3f(-1.01, 0.0, -0.05);
	glVertex3f(-1.01, 0.09, -0.05);
	glVertex3f(-1.01, 0.09, -0.1);
	glVertex3f(-1.01, 0.0, -0.1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-1.01, 0.0, -0.4);
	glVertex3f(-1.01, 0.09, -0.4);
	glVertex3f(-1.01, 0.09, -0.45);
	glVertex3f(-1.01, 0.0, -0.45);
	glEnd();
}

void glass() {
	glBegin(GL_QUADS);
	glVertex3f(-1.01, 0.3, -0.05);
	glVertex3f(-1.01, 0.8, -0.05);
	glVertex3f(-1.01, 0.8, -0.45);
	glVertex3f(-1.01, 0.3, -0.45);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-0.35, 0.8, -0.501);
	glVertex3f(-0.35, 0.4, -0.501);
	glVertex3f(-0.8, 0.4, -0.501);
	glVertex3f(-0.8, 0.8, -0.501);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-0.35, 0.8, 0.001);
	glVertex3f(-0.35, 0.4, 0.001);
	glVertex3f(-0.8, 0.4, 0.001);
	glVertex3f(-0.8, 0.8, 0.001);
	glEnd();
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;
	float theta = 0.0f;

	/* register window class */
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "GLSample";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


	if (!RegisterClassEx(&wcex))
		return 0;

	/* create main window */
	hwnd = CreateWindowEx(0,
		"GLSample",
		"OpenGL Sample",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		512,
		512,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);

	/* enable OpenGL for the window */
	EnableOpenGL(hwnd, &hDC, &hRC);
	glEnable(GL_DEPTH_TEST);

	/* program main loop */
	while (!bQuit)
	{
		/* check for messages */
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* handle or dispatch messages */
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			/* OpenGL animation code goes here */

			glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glLoadIdentity();
			glRotatef(xrot, 1, 0, 0);
			glRotatef(yrot, 0, 1, 0);
			glRotatef(zrot, 0, 0, 1);
			glScalef(0.3, 0.3, 1);
			glPushMatrix();
			glColor3f(0.4f, 0.6f, 0.88f);
			containre();
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0f, 0.95f, 0.95f);
			body_down();
			glPopMatrix();

			glPushMatrix();
			body();
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);
			fari();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0.7f, 0.9f, 0.93f);
			glass();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0, 0, 0);
			wheels_up();
			wheels_down();
			glPopMatrix();
			if (GetKeyState(VK_UP) == 1) {
				xrot += 1;
			};

			if (GetKeyState(VK_DOWN)) {
				xrot -= 1;
			};

			if (GetKeyState(VK_RIGHT)) {
				yrot -= 1;
			};

			if (GetKeyState(VK_LEFT)) {
				yrot += 1;
			};
			SwapBuffers(hDC);
			//rtri += 0.2;

			Sleep(1);
		}
	}

	/* shutdown OpenGL */
	DisableOpenGL(hwnd, hDC, hRC);

	/* destroy the window explicitly */
	DestroyWindow(hwnd);

	return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

		}

		
	}
	break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	/* get the device context (DC) */
	*hDC = GetDC(hwnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);

	SetPixelFormat(*hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
	*hRC = wglCreateContext(*hDC);

	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}