#include <bits/stdc++.h>
using namespace std;
#define myPositiveInfinite 2147483647
#define TRUE 1
#define FALSE 0

struct node {
    int key;
    struct node *next;
};

struct node *push(struct node *top, int element) {
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->key = element;
    newNode->next = top;
    top = newNode;
    return top;
}

int pop(struct node **top) {
    struct node *actualNode;
    int element;
    actualNode = *top;
    element = actualNode->key;
    *top = actualNode->next;
    free(actualNode);
    return element;
}
/*
void printStack(struct node *top) {
    struct node *actualNode;
    actualNode = top;
    while (actualNode != NULL) {
        printf("%d ", actualNode->key);
        actualNode = actualNode->next;
    }
    printf("\n");
}
*/
int stackEmpty(struct node *top) {
    return top == NULL ? TRUE : FALSE;
}

int getMin(struct node *minStack) {
    if (stackEmpty(minStack)) {
        printf("EMPTY\n");
        return myPositiveInfinite; // or another appropriate value
    } else {
        return minStack->key;
    }
}

int pr(char op)
{
	if(op=='+')
		return 1;
	if(op == '*')
		return 2;
	return 0;
}

int main()
{
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < 100; ++i)
	{
		string sprev=s;
		s = regex_replace(s,regex("\\(\\)"), "(1)");
		s = regex_replace(s,regex("\\)\\("), ")*(");
		s = regex_replace(s,regex("\\)\\)"), ")+1)");
		if(s==sprev)
			break;
	}
	stack<int> v;
	stack<char> o;
	for(char c : s)
	{
		if(c == '(')
			o.push(c);
		else if(c == '1')
			v.push(1);
		else if(c == ')')
		{
			while(!o.empty() && o.top() != '(')
			{
				int x=v.top();v.pop();
				int y=v.top();v.pop();
				char op=o.top();o.pop();
				v.push(op=='+'?x+y:x*y);
			}
			if(!o.empty())
				o.pop();
		}
		else
		{
			while(!o.empty() && pr(o.top()) >= pr(c))
			{
				int x=v.top();v.pop();
				int y=v.top();v.pop();
				char op=o.top();o.pop();
				v.push(op=='+'?x+y:x*y);
			}
			o.push(c);
		}
	}
	while(!o.empty())
	{
		int x=v.top();v.pop();
		int y=v.top();v.pop();
		char op=o.top();o.pop();
		v.push(op=='+'?x+y:x*y);
	}
	cout << v.top() << '\n';
	return 0;
}
