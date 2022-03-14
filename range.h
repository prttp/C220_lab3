#pragma once
template<typename T>
class Range {
    const T _left;
    const T _right;
public:
    constexpr Range(const T& left, const T& right) :
        _left(left < right ? left : right),
        _right(right > left ? right : left) {
    }
    constexpr const T& left()  const { return _left; }
    constexpr const T& right() const { return _right; }
    constexpr bool inside(const T& x) const {
        return x >= _left && x <= _right;
    }
    constexpr const T& check(const T& x)const {
        return inside(x) ? x : (x < _left ? _left : _right);
    }
};