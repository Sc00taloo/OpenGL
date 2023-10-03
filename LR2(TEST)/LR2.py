import pygame
import math
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

def points():
    glBegin(GL_LINE_STRIP)
    dx = 800 / 99
    start = 0
    for i in range(100):
        glVertex2f(start, (math.sin(start)) + 200)
        start += dx
    glEnd()

def iterate():
    glViewport(0, 0, 800,400)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0.0, 800, 0.0, 400, -1.0, 1.0)
    glMatrixMode (GL_MODELVIEW)
    glLoadIdentity()

def screen():
    glClearColor(0, 0, 0, 0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()

    iterate()
    glColor3f(1.0, 0.72, 0.11)
    points()
    glutSwapBuffers()

glutInit() 
glutInitDisplayMode(GLUT_RGBA)
wind = glutCreateWindow("OpenGL Coding Practice")
glutDisplayFunc(screen)
glutIdleFunc(screen)
glutMainLoop()
