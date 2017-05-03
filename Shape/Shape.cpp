// Shape.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "Shape.h"

const int NUM_IMAGE = 20;
shapeType input[NUM_IMAGE]{ RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC };

int main()
{
	srand((unsigned)time(nullptr));
	Shape* shape[NUM_IMAGE];
	for (int i = 0; i < NUM_IMAGE; i++)
	{
		shape[i] = Shape::findAndClone(input[i]);
		shape[i]->SetNo(i+1);
	}
	for (int i = 0; i < NUM_IMAGE; i++)
	{
		shape[i]->Draw();
		/*cout << GenerateRand() << "     " << time <<endl;*/
	}
	for (int i = 0; i < NUM_IMAGE; i++)
		delete shape[i];

	system("pause");
    return 0;
}

