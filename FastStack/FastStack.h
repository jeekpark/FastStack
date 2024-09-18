#pragma once

#include <cassert>
#include <vector>

template <class _Type>
class FastStack
{
public:
    using value_type = typename std::vector<_Type>::value_type;
    using reference = typename std::vector<_Type>::reference;
    using const_reference = typename std::vector<_Type>::const_reference;
    using size_type = typename std::vector<_Type>::size_type;
    using container_type = std::vector<_Type>;

    static_assert(std::is_object_v<_Type>, "Type must be an object type. Forbidden for void, function, and reference types.");

    FastStack() = default;

    explicit FastStack(const std::vector<_Type>& vector)
        : mContainer(vector)
    {
    }

    explicit FastStack(std::vector<_Type>&& vector) noexcept(std::is_nothrow_move_constructible_v<std::vector<_Type>>)
        : mContainer(std::move(vector))
    {
    }



protected:
    std::vector<_Type> mContainer;
};