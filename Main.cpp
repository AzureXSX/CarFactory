#include "Solutions.cpp"

class Car_components
{
public:
	string Base_type;
	string Wheel_type;
	string color;
	int volume;
	virtual ~Car_components() {};
	virtual void info() = 0;
};





class Car_1st : public Car_components
{
public:
	void input()
	{
		cinX(Base_type, "Enter Base type:");
		cinX(Wheel_type, "Enter wheel type:");
		cinX(color, "Enter color:");
		cinX(volume, "Enter engine volume:", '+');
	}
	void info() override
	{
		
		input();
		cout << "\n\tBase - [" << this->Base_type << "]" << endl;
		cout << "\tWheels - [" << this->Wheel_type << "]" << endl;
		cout << "\tColor - [" << this->color << "]" << endl;
		cout << "\tEngine volume - [" << this->volume << "]" << endl;
		cout << "\n";
	}
};

class Car_2nd : public Car_components
{
public:
	void input()
	{
		cinX(Base_type, "Enter Base type:");
		cinX(Wheel_type, "Enter wheel type:");
		cinX(color, "Enter color:");
		cinX(volume, "Enter engine volume:", '+');
	}
	void info() override
	{
		input();
		cout << "\n\tBase - [" << this->Base_type << "]" << endl;
		cout << "\tWheels - [" << this->Wheel_type << "]" << endl;
		cout << "\tColor - [" << this->color << "]" << endl;
		cout << "\tEngine volume - [" << this->volume << "]" << endl;
		cout << "\n";
	}
};







class CarFactory
{
public:
	virtual	Car_components* createCar() = 0;
	virtual ~CarFactory() {};

};




class Car_1stFactory : public CarFactory
{
public:
	Car_components* createCar() override
	{
		return new Car_1st;
	}
};

class Car_2ndFactory : public CarFactory
{
public:
	Car_components* createCar() override
	{
		return new Car_2nd;
	}
};






class Cars
{
public:
	vector< Car_components*> cr;
	~Cars()
	{
		int i;
		for (i = 0; i < cr.size(); i++) delete cr[i];
	}
	void show_inf()
	{
		int i;
		for (i = 0; i < cr.size(); i++) cr[i]->info();
	}
};




class FABRIC
{
public:
	Cars* createCars(CarFactory& factory)
	{
		Cars* p = new Cars;
		p->cr.push_back(factory.createCar());
		return p;
	}
};
int main()
{
	FABRIC f;
	Car_1stFactory cr1fac;
	Car_2ndFactory cr2fac;

	Cars* c1 = f.createCars(cr1fac);
	Cars* c2 = f.createCars(cr2fac);
	cout << "\n\t1st Type -> " << endl;
	c1->show_inf();
	cout << "\n\t2ndType -> " << endl;
	c2->show_inf();
}