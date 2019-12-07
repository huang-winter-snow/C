#include <iostream>

using namespace std;

class Singleton
{
private:
	Singleton()
	{
		cout << "constructor called!" << endl;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;
	static Singleton* instance;

public:
	~Singleton()
	{
		cout << "destructor called!" << endl;
	}	

	static Singleton* getInstance()
	{
		if (instance == nullptr) {
			instance = new Singleton;
		}

		return instance;
	}
};

Singleton* Singleton::instance = nullptr;

int main(int argc, char const *argv[])
{
	Singleton* instance1 = Singleton::getInstance();
	Singleton* instance2 = Singleton::getInstance();
	return 0;
}