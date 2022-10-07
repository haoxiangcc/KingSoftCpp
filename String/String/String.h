#pragma once
#include<iostream>

class CustomString
{
public:
	CustomString(const char* s);
	CustomString(const CustomString& s);
	CustomString(const CustomString&& s) noexcept;
	~CustomString();

	CustomString& operator=(const CustomString& s);
	CustomString& operator=(const CustomString&& s) noexcept;
	CustomString& operator=(const char* s);
	bool operator==(const CustomString& s);

	inline const int len() { return this->length; };

	CustomString sub(int start, int end);
	void  append(const char* s);
	void  append(const CustomString& s);

	int find(const char* s);

	CustomString* split(const char* s);


	friend std::ostream& operator<<(std::ostream& out, CustomString& s);

private:
	char* str;
	int length;
};


