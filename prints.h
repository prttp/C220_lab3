#pragma once
#include <vector>
#include <queue>
#include <typeinfo>
template<typename T>
void PrintAnyCont(const T& c) {
	/*if constexpr (std::is_pointer<std::decay<typename T::value_type>::type>::value) {
		for (const auto& el : c) {
			std::cout << *el << "   ";
		};
	}	else {
		for (const auto& el : c) {
			std::cout << el << "   ";
		}
	};
	std::cout << std::endl;*/

	for (const auto& el : c) {
		if constexpr (std::is_pointer<std::decay<decltype(el)>::type>::value) {
			std::cout << *el << "   ";
		}
		else {
			std::cout << el << "   ";
		}
	}
	std::cout << std::endl;

}
template <typename F, typename S>
auto sum(F& first, const S& second) {
	if constexpr (std::is_same<std::decay<F>::type, std::vector<S>>::value) {
		for (auto& i : first) { i += second; }
		return first;
	}
	else {
		return first + second;
	}
}

template<typename T>
const T& GetTop(std::queue<T>& s) {
	return s.front();
};
template<typename T>
const typename T::value_type& GetTop(T& s)
{
	return s.top();
};

template<typename T>
void PrintAnyAdapter(T cont) {
	/*struct inner_t : public C<T> {
		using C<T>::c;
	};
	const auto& inner = static_cast<const inner_t&>(cont).c;

	for (const auto& el : inner) {
		std::cout << el << "    ";
	}
	std::cout << std::endl;*/

	if constexpr (std::is_pointer<std::decay<typename T::value_type>::type>::value) {
		while (!cont.empty()) {
			std::cout << *(GetTop(cont)) << "    ";
			cont.pop();
		}

	}
	else {
		while (!cont.empty()) {
			std::cout << GetTop(cont) << "    ";
			cont.pop();
		}
	}
	std::cout << std::endl;
};

template<typename T>
constexpr T Smth() { 
	if constexpr (std::is_same<T, int>::value) {
		return 1;
	}
	else if constexpr (std::is_same <T, double>::value) {
		return 2.2;
	}
	else if constexpr (std::is_convertible <T, std::string>::value) {
		return std::string("abc");
	}
	else { return 0; }
	/*return (std::is_same<std::decay<T>::type, int>::value) ? 1 : (std::is_same < std::decay<T>::type, double>::value) ? 2.2 : "abc";*/
}

