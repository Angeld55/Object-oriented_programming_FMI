#pragma once
class Animal
{
public:
	virtual void roar() const = 0; //�������� � ��� �������������
	virtual Animal* clone() const = 0; //����� ��� �����
	virtual int getType() const = 0;
	virtual ~Animal() = default;
};

