// Automatically generated by the Fast Binary Encoding compiler, do not modify!
// https://github.com/chronoxor/FastBinaryEncoding
// Source: trade.fbe
// Version: 1.3.0.0

#pragma once

#if defined(__clang__)
#pragma clang system_header
#elif defined(__GNUC__)
#pragma GCC system_header
#elif defined(_MSC_VER)
#pragma system_header
#endif

#include "fbe.h"

namespace trade {
using namespace FBE;
} // namespace trade

namespace FBE {
using namespace ::trade;
} // namespace FBE

namespace trade {

enum class OrderSide : uint8_t
{
    buy,
    sell,
};

template <class TOutputStream>
inline TOutputStream& operator<<(TOutputStream& stream, OrderSide value)
{
    if (value == OrderSide::buy) { stream << "buy"; return stream; }
    if (value == OrderSide::sell) { stream << "sell"; return stream; }
    stream << "<unknown>";
    return stream;
}

} // namespace trade

namespace trade {

enum class OrderType : uint8_t
{
    market,
    limit,
    stop,
};

template <class TOutputStream>
inline TOutputStream& operator<<(TOutputStream& stream, OrderType value)
{
    if (value == OrderType::market) { stream << "market"; return stream; }
    if (value == OrderType::limit) { stream << "limit"; return stream; }
    if (value == OrderType::stop) { stream << "stop"; return stream; }
    stream << "<unknown>";
    return stream;
}

} // namespace trade

namespace trade {

struct Order
{
    int32_t id;
    std::string symbol;
    ::trade::OrderSide side;
    ::trade::OrderType type;
    double price;
    double volume;

    size_t fbe_type() const noexcept { return 1; }

    Order()
        : id((int32_t)0ll)
        , symbol()
        , side()
        , type()
        , price((double)0.0)
        , volume((double)0.0)
    {}
    Order(int32_t arg_id, const std::string& arg_symbol, const ::trade::OrderSide& arg_side, const ::trade::OrderType& arg_type, double arg_price, double arg_volume)
        : id(arg_id)
        , symbol(arg_symbol)
        , side(arg_side)
        , type(arg_type)
        , price(arg_price)
        , volume(arg_volume)
    {}
    Order(const Order& other) = default;
    Order(Order&& other) = default;
    ~Order() = default;

    Order& operator=(const Order& other) = default;
    Order& operator=(Order&& other) = default;

    bool operator==(const Order& other) const noexcept
    {
        return (
            (id == other.id)
            );
    }
    bool operator!=(const Order& other) const noexcept { return !operator==(other); }
    bool operator<(const Order& other) const noexcept
    {
        if (id < other.id)
            return true;
        if (other.id < id)
            return false;
        return false;
    }
    bool operator<=(const Order& other) const noexcept { return operator<(other) || operator==(other); }
    bool operator>(const Order& other) const noexcept { return !operator<=(other); }
    bool operator>=(const Order& other) const noexcept { return !operator<(other); }

    std::string string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream, const Order& value);

    void swap(Order& other) noexcept
    {
        using std::swap;
        swap(id, other.id);
        swap(symbol, other.symbol);
        swap(side, other.side);
        swap(type, other.type);
        swap(price, other.price);
        swap(volume, other.volume);
    }

    friend void swap(Order& value1, Order& value2) noexcept
    {
        value1.swap(value2);
    }
};

template <class TOutputStream>
inline TOutputStream& operator<<(TOutputStream& stream, const Order& value)
{
    stream << "Order(";
    stream << "id="; stream << value.id;
    stream << ",symbol="; stream << "\"" << value.symbol << "\"";
    stream << ",side="; stream << value.side;
    stream << ",type="; stream << value.type;
    stream << ",price="; stream << value.price;
    stream << ",volume="; stream << value.volume;
    stream << ")";
    return stream;
}

} // namespace trade

namespace std {

template<>
struct hash<trade::Order>
{
    typedef trade::Order argument_type;
    typedef size_t result_type;

    result_type operator () (const argument_type& value) const
    {
        result_type result = 17;
        result = result * 31 + std::hash<decltype(value.id)>()(value.id);
        return result;
    }
};

} // namespace std

namespace trade {

struct Balance
{
    std::string currency;
    double amount;

    size_t fbe_type() const noexcept { return 2; }

    Balance()
        : currency()
        , amount((double)0.0)
    {}
    Balance(const std::string& arg_currency, double arg_amount)
        : currency(arg_currency)
        , amount(arg_amount)
    {}
    Balance(const Balance& other) = default;
    Balance(Balance&& other) = default;
    ~Balance() = default;

    Balance& operator=(const Balance& other) = default;
    Balance& operator=(Balance&& other) = default;

    bool operator==(const Balance& other) const noexcept
    {
        return (
            (currency == other.currency)
            );
    }
    bool operator!=(const Balance& other) const noexcept { return !operator==(other); }
    bool operator<(const Balance& other) const noexcept
    {
        if (currency < other.currency)
            return true;
        if (other.currency < currency)
            return false;
        return false;
    }
    bool operator<=(const Balance& other) const noexcept { return operator<(other) || operator==(other); }
    bool operator>(const Balance& other) const noexcept { return !operator<=(other); }
    bool operator>=(const Balance& other) const noexcept { return !operator<(other); }

    std::string string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream, const Balance& value);

    void swap(Balance& other) noexcept
    {
        using std::swap;
        swap(currency, other.currency);
        swap(amount, other.amount);
    }

    friend void swap(Balance& value1, Balance& value2) noexcept
    {
        value1.swap(value2);
    }
};

template <class TOutputStream>
inline TOutputStream& operator<<(TOutputStream& stream, const Balance& value)
{
    stream << "Balance(";
    stream << "currency="; stream << "\"" << value.currency << "\"";
    stream << ",amount="; stream << value.amount;
    stream << ")";
    return stream;
}

} // namespace trade

namespace std {

template<>
struct hash<trade::Balance>
{
    typedef trade::Balance argument_type;
    typedef size_t result_type;

    result_type operator () (const argument_type& value) const
    {
        result_type result = 17;
        result = result * 31 + std::hash<decltype(value.currency)>()(value.currency);
        return result;
    }
};

} // namespace std

namespace trade {

struct Account
{
    int32_t id;
    std::string name;
    ::trade::Balance wallet;
    std::vector<::trade::Order> orders;

    size_t fbe_type() const noexcept { return 3; }

    Account()
        : id((int32_t)0ll)
        , name()
        , wallet()
        , orders()
    {}
    Account(int32_t arg_id, const std::string& arg_name, const ::trade::Balance& arg_wallet, const std::vector<::trade::Order>& arg_orders)
        : id(arg_id)
        , name(arg_name)
        , wallet(arg_wallet)
        , orders(arg_orders)
    {}
    Account(const Account& other) = default;
    Account(Account&& other) = default;
    ~Account() = default;

    Account& operator=(const Account& other) = default;
    Account& operator=(Account&& other) = default;

    bool operator==(const Account& other) const noexcept
    {
        return (
            (id == other.id)
            );
    }
    bool operator!=(const Account& other) const noexcept { return !operator==(other); }
    bool operator<(const Account& other) const noexcept
    {
        if (id < other.id)
            return true;
        if (other.id < id)
            return false;
        return false;
    }
    bool operator<=(const Account& other) const noexcept { return operator<(other) || operator==(other); }
    bool operator>(const Account& other) const noexcept { return !operator<=(other); }
    bool operator>=(const Account& other) const noexcept { return !operator<(other); }

    std::string string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    template <class TOutputStream>
    friend TOutputStream& operator<<(TOutputStream& stream, const Account& value);

    void swap(Account& other) noexcept
    {
        using std::swap;
        swap(id, other.id);
        swap(name, other.name);
        swap(wallet, other.wallet);
        swap(orders, other.orders);
    }

    friend void swap(Account& value1, Account& value2) noexcept
    {
        value1.swap(value2);
    }
};

template <class TOutputStream>
inline TOutputStream& operator<<(TOutputStream& stream, const Account& value)
{
    stream << "Account(";
    stream << "id="; stream << value.id;
    stream << ",name="; stream << "\"" << value.name << "\"";
    stream << ",wallet="; stream << value.wallet;
    {
        bool first = true;
        stream << ",orders=[" << value.orders.size() << "][";
        for (const auto& it : value.orders)
        {
            stream << std::string(first ? "" : ",") << it;
            first = false;
        }
        stream << "]";
    }
    stream << ")";
    return stream;
}

} // namespace trade

namespace std {

template<>
struct hash<trade::Account>
{
    typedef trade::Account argument_type;
    typedef size_t result_type;

    result_type operator () (const argument_type& value) const
    {
        result_type result = 17;
        result = result * 31 + std::hash<decltype(value.id)>()(value.id);
        return result;
    }
};

} // namespace std
