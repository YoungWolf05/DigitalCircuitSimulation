#pragma once
#include <vector>
#include <optional>
#include <queue>

template <typename T>
class PriorityQueue
{
public:
    std::optional<T> min() const 
    {
        if (len() == 0)
            return std::nullopt;
        return m_queue.top();
    }
    std::optional<T> pop()
    {
        if (len() == 0)
            return std::nullopt;

        T ret = m_queue.top();
        m_queue.pop();
        return ret;
    }
    size_t len() const noexcept { return m_queue.size(); }
    void append(const T& item) { m_queue.push(item); }

private:
    struct MinPriority {
        bool operator()(const T& t1, const T& t2) const {
            return t1.time > t2.time;
        }
    };
    std::priority_queue<T, std::vector<T>, MinPriority> m_queue;

};
