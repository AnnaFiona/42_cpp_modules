#pragma once

#include <exception>
#include <string>

template<typename T>
int	easyfind(const T cont, const int num) throw(invalid_argument()) {

	for (std::size_t x = 0; x < cont.size(); x++) {
		if (cont[x] == num)
			return (cont[x]);
	}
	throw (invalid_argument("num is not in the container"));
}