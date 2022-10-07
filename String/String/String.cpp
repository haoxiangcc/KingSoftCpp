#include <iostream>
#include "String.h"


CustomString::CustomString(const char* s = nullptr) :str(nullptr),length(0)
{
	int i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			i++;
		}
		if (i == 0)
		{
			return;
		}
		this->length = i;
		//this->str = (char*)malloc(sizeof(char) * (i + 1));
		this->str = new char[i + 1];
		if(str != nullptr)memcpy(this->str, s, i + 1);
	}
	return;
}



CustomString::CustomString(const CustomString& s)
{
	if (s.length == 0)
	{
		this->str = nullptr;
		this->length = 0;
		return;
	}
	//this->str = (char*)malloc(sizeof(char) * (s.length + 1));
	this->str = new char[s.length + 1];
	this->length = s.length;
	if (str != nullptr)memcpy(this->str, s.str, s.length + 1);
}

CustomString::CustomString(const CustomString&& s) noexcept
{
	if (s.length == 0)
	{
		this->str = nullptr;
		this->length = 0;
		return;
	}
	//this->str = (char*)malloc(sizeof(char) * (s.length + 1));
	this->str = new char[s.length + 1];
	this->length = s.length;
	if (str != nullptr)memcpy(this->str, s.str, s.length + 1);
}

CustomString::~CustomString()
{
	if (str != nullptr)
	{
		delete[] str;
	}
	str = nullptr;
	length = 0;
}

CustomString& CustomString::operator=(const CustomString& s)
{
	int i = 0;
	if (this != &s)
	{
		if (s.length == 0)
		{
			this->str = nullptr;
			this->length = 0;
			return *this;
		}
		delete[] str;
		while (s.str[i] != '\0')
		{
			i++;
		}
		//str = (char*)malloc(sizeof(char) * (i + 1));
		this->str = new char[i + 1];
		length = s.length;
		if (str != nullptr)memcpy(this->str, s.str, i + 1);
	}
	return *this;
}

CustomString& CustomString::operator=(const CustomString&& s) noexcept
{
	int i = 0;
	if (this != &s)
	{
		if (s.length == 0)
		{
			this->str = nullptr;
			this->length = 0;
			return *this;
		}
		delete[] str;
		while (s.str[i] != '\0')
		{
			i++;
		}
		//str = (char*)malloc(sizeof(char) * (i + 1));
		this->str = new char[i + 1];
		length = s.length;
		if (str != nullptr)memcpy(this->str, s.str, i + 1);
	}
	return *this;
}

CustomString& CustomString::operator=(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (i != 0)
	{
		delete[] str;
		//str = (char*)malloc(sizeof(char) * (i + 1));
		this->str = new char[i + 1];
		length = i;
		if (str != nullptr)memcpy(this->str, s, i + 1);
	}
	else
	{
		this->str = nullptr;
		this->length = 0;
	}
	return *this;
}

bool CustomString::operator==(const CustomString& s)
{
	if (this->length != s.length)
	{
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] != s.str[i])
		{
			return false;
		}
	}
	return true;
}

CustomString CustomString::sub(int start, int end)
{
	if (start <0 || end >this->length + 1)return CustomString();
	char* temp = (char*)malloc(sizeof(char) * (end - start + 1));
	if (str != nullptr)
	{
		memcpy(temp, str,end-start);
		temp[end - start] = '\0';
		return CustomString(temp);
	}
	return CustomString();
}

void CustomString::append(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if(i)
	{
		//char* temp = (char*)malloc(sizeof(char) * (i + this->length + 1));
		char* temp = new char[i + this->length + 1];
		if (temp != nullptr)
		{
			memcpy(temp, this->str, sizeof(char) * this->length);
			memcpy(&temp[this->length], s, i + 1);
		}
		this->length += i;
		delete[] str;
		this->str = temp;
	}
	return;
}

void  CustomString::append(const CustomString& s)
{
	append(s.str);
}

int CustomString::find(const char* s)
{
	for (int i = 0; i < this->length; i++)
	{
		int j = 0;
		int n = i;
		while (s[j] != '\0' && (this->str[n] == s[j]))
		{
			n++;
			j++;
		}
		if (s[j] == '\0')
		{
			return i;
		}
	}
	return -1;
}

CustomString* CustomString::split(const char* s)
{
	int num = 0;
	for (int i = 0; i < this->length; i++)
	{
		int j = 0;
		int n = i;
		while (s[j] != '\0' && (this->str[n] == s[j]))
		{
			n++;
			j++;
		}
		if (s[j] == '\0')
		{
			i = n - 1;
			num++;
		}
	}
	CustomString* tempstr = new CustomString[num];
	int index = 0;
	num = 0;
	for (int i = 0; i < this->length; i++)
	{
		int j = 0;
		int n = i;
		while (s[j] != '\0' && (this->str[n] == s[j]))
		{
			n++;
			j++;
		}
		if (s[j] == '\0')
		{
			i = n - 1;
			char* temp = new char[i - index + 1];
			if (temp == nullptr)
			{
				return nullptr;
			}
			memcpy(temp, &this->str[index], sizeof(char) * (i - index));
			temp[i - index] = '\0';
			int length = i - index;
			tempstr[num].length = length;
			tempstr[num].str = temp;
			num++;
			index = n;
		}
	}
	//处理尾部情况
	if (index != this->length - 1)
	{
		char* temp = new char[this->length - index + 1];
		if (temp == nullptr)
		{
			return nullptr;
		}
		memcpy(temp, &this->str[index], sizeof(char) * (this->length - index));
		temp[this->length - index] = '\0';
		int length = this->length - index;
		tempstr[num].length = length;
		tempstr[num].str = temp;
	}

	return tempstr;
}
std::ostream& operator<<(std::ostream& out, CustomString& s)
{
	if(s.str)out << s.str << std::endl;
	return out;
}