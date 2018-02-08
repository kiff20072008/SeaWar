#include "Definitions.h"
#include "Field.h"

int main(int argc, char** argv)
{
	try {
		Field field;
		while (1)
		{
			field.reachAction();
		}

	}
	catch (std::exception &exc)
	{
		cerr << exc.what()<<endl;
	}
	system("pause");
	return 0;
}