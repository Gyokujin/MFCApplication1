#include <stdio.h>

void PrintA()
{
	int a = 10;
	void* voidPtr; // 보이드 포인터 선언.
	voidPtr = &a; // 보이드 포인터가 가르키는 대상을 지정한다. 하지만 포인터에 대한 자료형을 정하지 않았기 때문에 메모리 크기를 모르는 상태이다.

	printf("%d\n", *(int*)voidPtr); // 10. 다음과 같이 받으려는 변수와 같은 자료형으로 형변환하여 사용 가능하다.(접근하려는 자료형의 메모리 크기를 알아야 해서)

	int* intPtr = (int*)voidPtr; // 또는 새로운 포인터를 선언하여 할당도 가능하다.
	printf("%d\n", *intPtr); // 10
}

struct Person
{
	int id;
	char name[20];
};

int main()
{
	// PrintA();

	Person p = { 12, "Alice" };
	void* voidPtr2 = &p;
	
	printf("%d\n", ((Person*)voidPtr2)->id); // 구조체 또한 가능하다. 해당 메모리의 주소뿐만 아니라 크기를 알아야 하는 이유는 그 정보를 어디까지 읽어야 할지 정해야 하기 때문이다.
	printf("%s\n", ((Person*)voidPtr2)->name); // 각 자료형마다 읽어야 할 메모리의 수가 다르기 때문에 엉뚱한 값을 받아올 수도 있기 때문이다.

	return 0;
}