// Shape.cpp : 定义控制台应用程序的入口点。
//

#include "Shape.h"

const int NUM_SHAPE = 20;
shapeType input[NUM_SHAPE]{ RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,RECT,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC,CIRC };

int main()
{
	//Generate random seed
	srand((unsigned)time(nullptr));
	//Define shape array
	Shape* shape[NUM_SHAPE];
	
	//Generate shape object and push it into shape array by using prototype pattern
	for (int i = 0; i < NUM_SHAPE; i++)
	{
		shape[i] = Shape::findAndClone(input[i]);
		shape[i]->SetNo(i+1);
	}

	//Print the objects on the screen
	for (int i = 0; i < NUM_SHAPE; i++)
	{
		shape[i]->Draw();
	}
	
	//Marking
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "|                     New Array Through The Filter                       |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	//Filter the objects which its area is bigger than 50 and push it into a new array then delete the rest of the array member
	int index = 0;
	int n = NUM_SHAPE;
	while (index < n)
	{			
		if (shape[index]->GetArea() < 50)
		{

			for (int i = index;i < n -1; ++i)
			{
				shape[i] = shape[i + 1];
			}
			--n;
		}
		else
		{
			index++;
		}
	}

	//New array
	Shape** newArr = new Shape*[n];


	//Print the new array on the screen,delete the useless member and release its memory
	for (int i=0;i<n;i++)
	{
		newArr[i] = shape[i];
		newArr[i]->Draw();
		delete shape[i];
		shape[i] = nullptr;
	}

	//Reset the rest members to default nullptr
	for (int i = NUM_SHAPE-1; i >n-1; --i) 
	{
		shape[i] = nullptr;
	}


	//Free the memory that is used by new array
	delete newArr;
	newArr = nullptr;

	//shape = nullptr;

	system("pause");
    return 0;
}
