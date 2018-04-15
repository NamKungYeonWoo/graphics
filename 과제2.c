// ConsoleApplication2.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//
#include "stdafx.h"
#include<glut.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

static GLfloat PI = 3.141592,angle=0,angley=0;
static int tempx, tempy;
GLfloat eye[3] = { 0,0,0 }, at[3] = { 0,0,11 }, up[3] = { 0,1,0 };


void init() { // openGL �ʱ�ȭ
			  //srand(time(0));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // ������� = �������
	glClearColor(1.0, 1.0, 1.0, 1.0); // (r g b a(����)(1�� ������)����)(1�� �ִ밪 ���� ���� ��)
	glColor3f(0.0, 0.0, 1.0); // ���� �� ����(1 0 0 --> ������)
	glFrustum(-1,1,-1,1,1,20); // ��ǥ�� ũ�� ���� (left,right,bottom,top)
											  //ȭ�鿡���̴� ��ǥ ���� 
											  //glFrustum(-150, 150, -150, 150, -500, 500);
											  //gluPerspective(85.0, 1.0, 2.0, 20.0);
	glEnable(GL_DEPTH_TEST);   // �׽�Ʈ�� ����� DEPTH_BUFFER�� ����ȴ�.
							   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();		// �̰� ������ 2�� ȸ���� ��Ŀ� �� 4�� ȸ�� 6�� ȸ��..
							//gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
							//glRotatef(theta[0], 1.0, 0, 0); //theta��ŭ y�� �������� ȸ��
							//glRotatef(theta[1], 0, 1.0, 0);
							//glRotatef(theta[2], 0, 0, 1);
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	
	glPushMatrix();
	glTranslatef(0, 0, 5);            // ����
	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);          // ����
	glColor3f(1.0, 0.0, 1.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 0, 0);           // ����
	glColor3f(0.0, 1.0, 0.0);
	glutWireCone(1, 1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0, 0);
	glColor3f(0.0, 0.0, 1.0);         // ������
	glutWireTorus(0.5,0.5,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5, 0);          // ����
	glColor3f(0.0, 1.0, 1.0);
	glutWireSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -5, 0);         // �Ʒ���
	glColor3f(1.0, 0.5, 0.5);
	glutWireIcosahedron();
	glPopMatrix();

	glFlush();

}


void keyboard_handler(unsigned char key, int x, int y) {
	if (key == 'w') {        // ������->��üũ��           // ���� ư ���⿡���� ������ �̵� -> �� �׷��� ����
		eye[2] += 0.1*cos(angle*PI / 180.0);			   // z������ �̵��� ���� cos��ŭ �̵�
		eye[0] += 0.1*sin(angle*PI / 180.0);			   // x������ �̵��� ���� sin��ŭ �̵�
		at[2] += 0.1*cos(angle*PI / 180.0);				   // ���� ���� ���� ��������
		at[0] += 0.1*sin(angle*PI / 180.0);
	}
	if (key == 's') {       //�ڷΰ� ->��ü �۰Ժ���
		eye[2] += 0.1*-cos(angle*PI / 180.0);
		eye[0] += 0.1*-sin(angle*PI / 180.0);
		at[2] += 0.1*-cos(angle*PI / 180.0);
		at[0] += 0.1*-sin(angle*PI / 180.0);
	}
	if (key == 'a') {       //�����̵� -> ��ü ������        // ���� a��ŭ ư ���¿��� �¿� �̵� z����� ���� = 90-a
		eye[2] += 0.1*-cos((90 - angle)*PI / 180.0);         
		eye[0] += 0.1*sin((90-angle)*PI / 180.0);            
		at[2] += 0.1*-cos((90 - angle)*PI / 180.0);
		at[0] += 0.1*sin((90 - angle)*PI / 180.0);
	}
	if (key == 'd') {      // �������̵�-> ��ü ����
		eye[2] += 0.1*cos((90 - angle)*PI / 180.0);
		eye[0] += 0.1*-sin((90 - angle)*PI / 180.0);
		at[2] += 0.1*cos((90 - angle)*PI / 180.0);
		at[0] += 0.1*-sin((90 - angle)*PI / 180.0);
	}
	
	printf("%lf %lf %lf %lf\n", eye[0], eye[2], at[0], at[2]);
	glutPostRedisplay();
}


void mouse_handler(int btn, int state, int x, int y) { // x,y ���콺������ ��ġ��ǥ
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		tempx = x; tempy = y;
		printf("%d %d\n", x, y);
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		angle += (float)(x - tempx) / 25.0;
		if (angle > 360)
			angle -= 360;
		if(angle<-360)
			angle+=360;
		if (!(angley + (float)(y - tempy) / 25.0 > 90 || angley + (float)(y - tempy) / 25.0 < -90)) {     // y������ 90, -90�� �̻� �Ѿ�� �ȵ� ���� �Ѱ�
			angley += (float)(y - tempy) / 25.0;
			at[1] = eye[1]+ (angley*PI / 180);
		}
			
		at[0] = eye[0] + sin(angle*PI / 180);         // �� Ʋ�� ���� �״�� �þ� at�� �ٲ�
		at[2] = eye[2] + cos(angle*PI / 180);
		
		printf("%lf %lf\n", angle, angley);
		printf("at0 : %lf at1 %lf at2 %lf\n", at[0], at[1], at[2]);
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, (char**)argv); // �ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); // ������ũ���ʱ�ȭ(��ȭ��ũ��)(�����ϸ� ������ ȭ��)
	glutCreateWindow("FPS"); // ��������� 
												 //glutIdleFunc(spin_cube);
	glutKeyboardFunc(keyboard_handler);
	glutMouseFunc(mouse_handler);
	glutDisplayFunc(display);  // os�� ���� ȭ���� ��������(parameter�� �׸���)
							   //glutTimerFunc(delay, timer, 0);

	init(); // openGL �ʱ�ȭ
	glutMainLoop(); // event queue�� � event�� ����ִ��� �˻��ϴ� loop����

	return 0;
}