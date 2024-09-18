#pragma once

#include <cassert>
#include <vector>
#include <type_traits> 
#include <utility>

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

    void Reserve(size_type capacity)
    {
        mContainer.reserve(capacity);
    }

    size_type Capacity() const noexcept(noexcept(mContainer.capacity()))
    {
        return mContainer.capacity();
    }

    void Clear() noexcept(noexcept(mContainer.clear()))
    {
        mContainer.clear();
    }

    bool Empty() const noexcept(noexcept(mContainer.empty()))
    {
        return mContainer.empty();
    }

    size_type Size() const noexcept(noexcept(mContainer.size()))
    {
        return mContainer.size();
    }

    reference Top() noexcept(noexcept(mContainer.back()))
    {
        return mContainer.back();
    }

    const_reference Top() const noexcept(noexcept(mContainer.back()))
    {
        return mContainer.back();
    }

    void Push(const value_type& value)
    {
        mContainer.push_back(value);
    }

    void Push(value_type&& value)
    {
        mContainer.push_back(std::move(value));
    }

    template <class... _Args>
    void Emplace(_Args&&... args)
    {
        mContainer.emplace_back(std::forward<_Args>(args)...);
    }

    void Pop() noexcept(noexcept(mContainer.pop_back()))
    {
        mContainer.pop_back();
    }

    void Swap(FastStack& other) noexcept(noexcept(std::swap(mContainer, other.mContainer)))
    {
        std::swap(mContainer, other.mContainer);
    }

    const std::vector<_Type>& GetContainer() const noexcept
    {
        return mContainer;
    }

protected:
    std::vector<_Type> mContainer;
};

template <class _Type>
bool operator==(const FastStack<_Type>& lhs, const FastStack<_Type>& rhs)
{
    return lhs.GetContainer() == rhs.GetContainer();
}

template <class _Type>
bool operator!=(const FastStack<_Type>& lhs, const FastStack<_Type>& rhs)
{
    return lhs.GetContainer() != rhs.GetContainer();
}

template <class _Type>
bool operator<(const FastStack<_Type>& lhs, const FastStack<_Type>& rhs)
{
    return lhs.GetContainer() < rhs.GetContainer();
}

template <class _Type>
bool operator<=(const FastStack<_Type>& lhs, const FastStack<_Type>& rhs)
{
    return lhs.GetContainer() <= rhs.GetContainer();
}

template <class _Type>
bool operator>(const FastStack<_Type>& lhs, const FastStack<_Type>& rhs)
{
    return lhs.GetContainer() > rhs.GetContainer();
}

template <class _Type>
bool operator>=(const FastStack<_Type>& lhs, const FastStack<_Type>& rhs)
{
    return lhs.GetContainer() >= rhs.GetContainer();
}

template <class _Type>
void Swap(FastStack<_Type>& lhs, FastStack<_Type>& rhs) noexcept(noexcept(lhs.Swap(rhs)))
{
    lhs.Swap(rhs);
}
