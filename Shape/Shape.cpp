// Shape.cpp : 定义控制台应用程序的入口点。
//

#include "Shape.h"

const int NUM_IMAGE = 20;
shapeType input[NUM_IMAGE]{ RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC };

bool isGood(int i)
{
	return i < 50;
}

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
	}
	
	//for (int i = 0; i < NUM_IMAGE; i++)
	//{
	//	int n = NUM_IMAGE;
	//	if (shape[i]->GetArea() < 50)
	//	{
	//		for (int j = i; j < n - 1; j++)
	//		{
	//			*(shape[j]) = *(shape[j + 1]);
	//		}
	//		n--;
	//	}
	//}
	
	Shape* pEnd = remove_if(begin(shape), end(shape), isGood);

	for (int i = 0; i < NUM_IMAGE; i++)
	{
		pEnd->Draw();
	}

	for (int i = 0; i < NUM_IMAGE; i++)
		delete shape[i];

	system("pause");
    return 0;
}
