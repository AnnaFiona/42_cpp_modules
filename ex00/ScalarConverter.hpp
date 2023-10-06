#pragma once

#include <string>


class ScalarCoverter
{
public:
//con- and destructors
	ScalarCoverter();
	ScalarCoverter(const ScalarCoverter& S);
	ScalarCoverter& operator = (const ScalarCoverter& S);
	~ScalarCoverter();

//methods
	static void	convert(const std::string str);
};