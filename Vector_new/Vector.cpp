#include "Vector.h"


Vector::Vector()
{
	cur_size = 0;
	buf_size = 0;
	els = nullptr;
}

Vector::Vector(int size)
{
	cur_size = size;
	buf_size = size;
	els = new double[size];
	for (int i = 0;i < size;i++)
		els[i] = 0.0;
}

Vector::Vector (const Vector &obj)
{
	this->cur_size = obj.size();
	this->buf_size = obj.size();
	this->els = new double[size()];
	for (int i = 0;i < this->size();i++)
		this->els[i] = obj.els[i];
}

Vector Vector::operator=(const Vector &obj)
{
	this->cur_size = obj.size();
	this->buf_size = obj.size();
	this->els = new double[size()];
	for (int i = 0;i < this->size();i++)
		this->els[i] = obj.els[i];
	return *this;
}
Vector Vector::operator+(const Vector & obj)
{
	for (int i = cur_size; i < cur_size + obj.size(); i++)
		els[i] = obj.els[i - cur_size];
	cur_size += obj.size();
	buf_size += obj.buf_size;
	return *this;
}
Vector Vector::operator-(const Vector & obj)
{
	for (int i = 0; i < cur_size; i++)
	{
		for (int j = 0; j < obj.cur_size; j++)
		{
			if (els[i] == obj.els[j])
			{
				for (int k = i; k < cur_size - 1; k++)
				{
					els[k] = els[k + 1];
				}
				cur_size--;
			}
		}
	}
	return *this;
}
double& Vector::push_back(double val)
{
	if (buf_size <= 0)
	{
		buf_size = 2;
		els = new double[buf_size];
	}
	else
	{
		if (cur_size >= buf_size)
		{
			buf_size *= 2;
			double *tmp = new double[size()];
			for (int i = 0;i < size();i++)
				tmp[i] = els[i];
			delete[] els;
			els = tmp;
		}
	}
	els[cur_size++] = val;	
	return els[cur_size - 1];
}

double& Vector::at(int index)
{
	if (index<0 || index>size())
		return els[0];
	else
		return els[index];
}

double& Vector::operator[](int index)
{
	if (index<0 || index>size())
		return els[0];
	else
		return els[index];
}

bool Vector::operator==(const Vector &obj)
{
	if (cur_size != obj.cur_size)
		return false;
	else
		for (int i = 0;i < size();i++)
		{
			if (els[i] != obj.els[i])
			{
				return false;				
			}				
		}	
	return true;
}

bool Vector::operator!=(const Vector & obj)
{
	if (cur_size != obj.cur_size)
		return true;
	else
		for (int i = 0; i < size(); i++)
		{
			if (els[i] != obj.els[i])
			{
				return true;
			}
		}
	return false;
}

double & Vector::operator<<(int index)
{
	double temp;
	if (index < cur_size)
	{
		temp = els[index];
		for (int i = index; i < cur_size; i++)
		{
			els[i] = els[i + 1];			
		}
		cur_size--;
	}
	return temp;
}

ostream& operator<<(ostream& os, Vector v)
{
	for (int i = 0;i < v.size();i++)
		os << v[i] << "\t";
	return os;
}