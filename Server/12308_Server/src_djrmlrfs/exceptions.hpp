#ifndef SJTU_EXCEPTIONS_HPP
#define SJTU_EXCEPTIONS_HPP

#include <cstddef>
#include <cstring>
#include <string>

namespace sjtu {

class exception {
protected:
	const std::string variant = "";
	std::string detail = "";
public:
	exception() {}
	exception(const exception &ec) : variant(ec.variant), detail(ec.detail) {}
	virtual std::string what() {
		return variant + " " + detail;
	}
};

/**
 * TODO
 * Please complete them.
 */
class index_out_of_bound : public exception {
	public:
		index_out_of_bound()
		{
			detail = "OOB";
		}
	/* __________________________ */
};

class runtime_error : public exception {
	runtime_error()
	{
		detail = "RE";
	}
	/* __________________________ */
};

class invalid_iterator : public exception {
	invalid_iterator()
	{
		detail = "II";
	}
	/* __________________________ */
};

class container_is_empty : public exception {
public:
	container_is_empty()
	{
		detail = "CIE";
	}
	/* __________________________ */
};
}

#endif
