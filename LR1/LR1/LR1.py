#import OpenGL
#import OpenGL.GL
#import OpenGL.GLUT
#import OpenGL.GLU
#import pygame as pg

#from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

def square():
    glBegin(GL_QUADS)
    glVertex2f(250, 150)
    glVertex2f(550, 150)
    glVertex2f(550, 300)
    glVertex2f(250, 300)
    glEnd()

def tringle_black():
    glBegin(GL_TRIANGLES)
    glVertex2f(250, 170)
    glVertex2f(250, 280)
    glVertex2f(385, 225)

    glVertex2f(550, 170)
    glVertex2f(550, 280)
    glVertex2f(415, 225)
    glEnd()

def tringle_green():
    glBegin(GL_TRIANGLES)
    glVertex2f(270, 150)
    glVertex2f(530, 150)
    glVertex2f(400, 210)

    glVertex2f(270, 300)
    glVertex2f(530, 300)
    glVertex2f(400, 240)
    glEnd()

def iterate():
    glViewport(0, 0, 800,400)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0.0, 800, 0.0, 400, -1.0, 1.0)
    glMatrixMode (GL_MODELVIEW)
    glLoadIdentity()

def screen():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    iterate()
    glColor3f(1.0, 0.72, 0.11)
    square()
    glColor3f(0.0, 0.46, 0.28)
    tringle_green()
    glColor3f(0.0, 0.0, 0.0)
    tringle_black()
    glutSwapBuffers()

glutInit() 
glutInitDisplayMode(GLUT_RGBA)
glutInitWindowSize(800, 400)
glutInitWindowPosition(0, 0)
wind = glutCreateWindow("OpenGL Coding Practice")
glutDisplayFunc(screen)
glutIdleFunc(screen)
glutMainLoop()