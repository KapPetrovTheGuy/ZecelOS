# Contribution rules

* Use tabs
* Use PascalCase for function and types
* Use camelCase for variables
* Use UPPER\_SNAKE\_CASE for defines/macros and constants
* If the code is 1 line remove braces from if,while or for

## Example
```
#define DEFINE_TEST 543

const int CONSTANT_TEST = 542;

typedef struct {
	int x, y;
} TestType;

int SomeCode(void)
{
	int someVariable = 2312;

	if (DEFINE_TEST == CONSTANT_TEST)
		return 1;
	else {
		printf("tset %d\n", someVariable);
		return 0;
	}
}
