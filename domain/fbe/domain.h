// Automatically generated by the Fast Binary Encoding compiler, do not modify!

#pragma once

#include "common.h"

namespace domain {
using namespace FBE;
} // namespace domain

namespace FBE {
using namespace domain;
} // namespace FBE

namespace domain {

enum class OrderSide : uint8_t
{
    buy,
    sell,
};

inline std::ostream& operator<<(std::ostream& stream, OrderSide e)
{
    if (e == OrderSide::buy) return stream << "buy";
    if (e == OrderSide::sell) return stream << "sell";
    return stream << "<unknown>";
}

} // namespace domain

namespace FBE {

template <class TBuffer>
class FieldModel<TBuffer, OrderSide> : public FieldModelBase<TBuffer, OrderSide, uint8_t>
{
public:
    using FieldModelBase<TBuffer, OrderSide, uint8_t>::FieldModelBase;
};

} // namespace FBE

namespace domain {

enum class OrderType : uint8_t
{
    market,
    limit,
    stop,
};

inline std::ostream& operator<<(std::ostream& stream, OrderType e)
{
    if (e == OrderType::market) return stream << "market";
    if (e == OrderType::limit) return stream << "limit";
    if (e == OrderType::stop) return stream << "stop";
    return stream << "<unknown>";
}

} // namespace domain

namespace FBE {

template <class TBuffer>
class FieldModel<TBuffer, OrderType> : public FieldModelBase<TBuffer, OrderType, uint8_t>
{
public:
    using FieldModelBase<TBuffer, OrderType, uint8_t>::FieldModelBase;
};

} // namespace FBE

namespace domain {

struct Order
{
    int32_t id;
    std::string symbol;
    OrderSide side;
    OrderType type;
    double price;
    double volume;

    Order()
        : id()
        , symbol()
        , side()
        , type()
        , price((double)0.0)
        , volume((double)0.0)
    {}

    Order(int32_t arg_id, const std::string& arg_symbol, const OrderSide& arg_side, const OrderType& arg_type, double arg_price, double arg_volume)
        : id(arg_id)
        , symbol(arg_symbol)
        , side(arg_side)
        , type(arg_type)
        , price(arg_price)
        , volume(arg_volume)
    {}

    bool operator==(const Order& s) const noexcept
    {
        return (
            (id == s.id)
            );
    }
    bool operator!=(const Order& s) const noexcept { return !operator==(s); }
    bool operator<(const Order& s) const noexcept
    {
        if (id < s.id)
            return true;
        if (s.id < id)
            return false;
        return false;
    }
    bool operator<=(const Order& s) const noexcept { return operator<(s) || operator==(s); }
    bool operator>(const Order& s) const noexcept { return !operator<=(s); }
    bool operator>=(const Order& s) const noexcept { return !operator<(s); }

    std::string string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& stream, const Order& s);

    void swap(Order& s) noexcept
    {
        using std::swap;
        swap(id, s.id);
        swap(symbol, s.symbol);
        swap(side, s.side);
        swap(type, s.type);
        swap(price, s.price);
        swap(volume, s.volume);
    }

    friend void swap(Order& s1, Order& s2) noexcept
    {
        s1.swap(s2);
    }
};

inline std::ostream& operator<<(std::ostream& stream, const Order& s)
{
    stream << "Order(";
    stream << "id="; stream << s.id;
    stream << ",symbol="; stream << "\"" << s.symbol << "\"";
    stream << ",side="; stream << s.side;
    stream << ",type="; stream << s.type;
    stream << ",price="; stream << s.price;
    stream << ",volume="; stream << s.volume;
    stream << ")";
    return stream;
}

} // namespace domain

namespace FBE {

template <class TBuffer>
class FieldModel<TBuffer, Order>
{
public:
    FieldModel(TBuffer& buffer, size_t offset) noexcept : _buffer(buffer), _offset(offset)
        , id(buffer, 4 + 4)
        , symbol(buffer, id.fbe_offset() + id.fbe_size())
        , side(buffer, symbol.fbe_offset() + symbol.fbe_size())
        , type(buffer, side.fbe_offset() + side.fbe_size())
        , price(buffer, type.fbe_offset() + type.fbe_size())
        , volume(buffer, price.fbe_offset() + price.fbe_size())
    {}

    // Get the field type
    size_t fbe_type() const noexcept { return 1; }
    // Get the field offset
    size_t fbe_offset() const noexcept { return _offset; }
    // Get the field size
    size_t fbe_size() const noexcept { return 4; }
    // Get the field body size
    size_t fbe_body() const noexcept
    {
        size_t fbe_result = 4 + 4
            + id.fbe_size()
            + symbol.fbe_size()
            + side.fbe_size()
            + type.fbe_size()
            + price.fbe_size()
            + volume.fbe_size()
            ;
        return fbe_result;
    }
    // Get the field extra size
    size_t fbe_extra() const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4) > _buffer.size())
            return 0;

        _buffer.shift(fbe_struct_offset);

        size_t fbe_result = fbe_body()
            + id.fbe_extra()
            + symbol.fbe_extra()
            + side.fbe_extra()
            + type.fbe_extra()
            + price.fbe_extra()
            + volume.fbe_extra()
            ;

        _buffer.unshift(fbe_struct_offset);

        return fbe_result;
    }

    // Shift the current field offset
    void fbe_shift(size_t size) noexcept { _offset += size; }
    // Unshift the current field offset
    void fbe_unshift(size_t size) noexcept { _offset -= size; }

    // Check if the struct value is valid
    bool verify(bool verify_type = true) const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return true;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4 + 4) > _buffer.size())
            return false;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset));
        if (fbe_struct_size < 4 + 4)
            return false;

        uint32_t fbe_struct_type = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset + 4));
        if (verify_type && (fbe_struct_type != fbe_type()))
            return false;

        _buffer.shift(fbe_struct_offset);
        bool fbe_result = verifyFields(fbe_struct_size);
        _buffer.unshift(fbe_struct_offset);
        return fbe_result;
    }

    // Check if the struct fields are valid
    bool verifyFields(size_t fbe_struct_size) const noexcept
    {
        size_t fbe_current_size = 4 + 4;

        if ((fbe_current_size + id.fbe_size()) > fbe_struct_size)
            return true;
        if (!id.verify())
            return false;
        fbe_current_size += id.fbe_size();

        if ((fbe_current_size + symbol.fbe_size()) > fbe_struct_size)
            return true;
        if (!symbol.verify())
            return false;
        fbe_current_size += symbol.fbe_size();

        if ((fbe_current_size + side.fbe_size()) > fbe_struct_size)
            return true;
        if (!side.verify())
            return false;
        fbe_current_size += side.fbe_size();

        if ((fbe_current_size + type.fbe_size()) > fbe_struct_size)
            return true;
        if (!type.verify())
            return false;
        fbe_current_size += type.fbe_size();

        if ((fbe_current_size + price.fbe_size()) > fbe_struct_size)
            return true;
        if (!price.verify())
            return false;
        fbe_current_size += price.fbe_size();

        if ((fbe_current_size + volume.fbe_size()) > fbe_struct_size)
            return true;
        if (!volume.verify())
            return false;
        fbe_current_size += volume.fbe_size();

        return true;
    }

    // Get the struct value (begin phase)
    size_t get_begin() const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4 + 4) > _buffer.size())
            return 0;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset));
        assert((fbe_struct_size >= 4 + 4) && "Model is broken!");
        if (fbe_struct_size < 4 + 4)
            return 0;

        _buffer.shift(fbe_struct_offset);
        return fbe_struct_offset;
    }

    // Get the struct value (end phase)
    void get_end(size_t fbe_begin) const noexcept
    {
        _buffer.unshift(fbe_begin);
    }

    // Get the struct value
    void get(Order& value) const noexcept
    {
        size_t fbe_begin = get_begin();
        if (fbe_begin == 0)
            return;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset()));

        getFields(value, fbe_struct_size);

        get_end(fbe_begin);
    }

    // Get the struct fields values
    void getFields(Order& value, size_t fbe_struct_size) const noexcept
    {
        size_t fbe_current_size = 4 + 4;

        if ((fbe_current_size + id.fbe_size()) <= fbe_struct_size)
            id.get(value.id);
        fbe_current_size += id.fbe_size();

        if ((fbe_current_size + symbol.fbe_size()) <= fbe_struct_size)
            symbol.get(value.symbol);
        fbe_current_size += symbol.fbe_size();

        if ((fbe_current_size + side.fbe_size()) <= fbe_struct_size)
            side.get(value.side);
        fbe_current_size += side.fbe_size();

        if ((fbe_current_size + type.fbe_size()) <= fbe_struct_size)
            type.get(value.type);
        fbe_current_size += type.fbe_size();

        if ((fbe_current_size + price.fbe_size()) <= fbe_struct_size)
            price.get(value.price, (double)0.0);
        else
            value.price = (double)0.0;
        fbe_current_size += price.fbe_size();

        if ((fbe_current_size + volume.fbe_size()) <= fbe_struct_size)
            volume.get(value.volume, (double)0.0);
        else
            value.volume = (double)0.0;
        fbe_current_size += volume.fbe_size();
    }

    // Set the struct value (begin phase)
    size_t set_begin()
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_size = (uint32_t)fbe_body();
        uint32_t fbe_struct_offset = (uint32_t)(_buffer.allocate(fbe_struct_size) - _buffer.offset());

        assert(((_buffer.offset() + fbe_struct_offset + fbe_struct_size) <= _buffer.size()) && "Model is broken!");

        *((uint32_t*)(_buffer.data() + _buffer.offset() + _offset)) = fbe_struct_offset;
        *((uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset)) = fbe_struct_size;
        *((uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset + 4)) = (uint32_t)fbe_type();

        _buffer.shift(fbe_struct_offset);
        return fbe_struct_offset;
    }

    // Set the struct value (end phase)
    void set_end(size_t fbe_begin)
    {
        _buffer.unshift(fbe_begin);
    }

    // Set the struct value
    void set(const Order& value) noexcept
    {
        size_t fbe_begin = set_begin();
        if (fbe_begin == 0)
            return;

        setFields(value);

        set_end(fbe_begin);
    }

    // Set the struct fields values
    void setFields(const Order& value) noexcept
    {
        id.set(value.id);
        symbol.set(value.symbol);
        side.set(value.side);
        type.set(value.type);
        price.set(value.price);
        volume.set(value.volume);
    }

private:
    TBuffer& _buffer;
    size_t _offset;

public:
    FieldModel<TBuffer, int32_t> id;
    FieldModel<TBuffer, std::string> symbol;
    FieldModel<TBuffer, OrderSide> side;
    FieldModel<TBuffer, OrderType> type;
    FieldModel<TBuffer, double> price;
    FieldModel<TBuffer, double> volume;
};

} // namespace FBE

namespace FBE {

template <class TBuffer>
class OrderModel : public FBE::Model<TBuffer>
{
public:
    OrderModel() : model(this->buffer(), 4) {}

    // Get the model type
    size_t fbe_type() const noexcept { return model.fbe_type(); }
    // Get the model size
    size_t fbe_size() const noexcept { return model.fbe_size() + model.fbe_extra(); }

    FieldModel<TBuffer, Order> model;

    // Check if the current struct value is valid
    bool verify()
    {
        if ((this->buffer().offset() + model.fbe_offset() - 4) > this->buffer().size())
            return false;

        uint32_t fbe_full_size = *((const uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4));
        if (fbe_full_size < model.fbe_size())
            return false;

        return model.verify();
    }

    // Create a new model (begin phase)
    size_t create_begin()
    {
        size_t fbe_begin = this->allocate(4 + model.fbe_size());
        return fbe_begin;
    }

    // Create a new model (end phase)
    size_t create_end(size_t fbe_begin)
    {
        size_t fbe_end = this->buffer().size();

        uint32_t fbe_full_size = (uint32_t)(fbe_end - fbe_begin);
        *((uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4)) = fbe_full_size;
        return fbe_full_size;
    }

    // Serialize the struct value
    size_t serialize(const Order& value)
    {
        size_t fbe_begin = create_begin();
        model.set(value);
        size_t fbe_full_size = create_end(fbe_begin);
        return fbe_full_size;
    }

    // Deserialize the struct value
    size_t deserialize(Order& value) const noexcept
    {
        if ((this->buffer().offset() + model.fbe_offset() - 4) > this->buffer().size())
            return 0;

        uint32_t fbe_full_size = *((const uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4));
        assert((fbe_full_size >= model.fbe_size()) && "Model is broken!");
        if (fbe_full_size < model.fbe_size())
            return 0;

        model.get(value);

        return fbe_full_size;
    }

    // Mode to the next struct value
    void next(size_t prev) noexcept
    {
        model.fbe_shift(prev);
    }
};

} // namespace FBE

namespace domain {

struct Balance
{
    std::string currency;
    double amount;

    Balance()
        : currency()
        , amount((double)0.0)
    {}

    Balance(const std::string& arg_currency, double arg_amount)
        : currency(arg_currency)
        , amount(arg_amount)
    {}

    bool operator==(const Balance& s) const noexcept
    {
        return (
            (currency == s.currency)
            );
    }
    bool operator!=(const Balance& s) const noexcept { return !operator==(s); }
    bool operator<(const Balance& s) const noexcept
    {
        if (currency < s.currency)
            return true;
        if (s.currency < currency)
            return false;
        return false;
    }
    bool operator<=(const Balance& s) const noexcept { return operator<(s) || operator==(s); }
    bool operator>(const Balance& s) const noexcept { return !operator<=(s); }
    bool operator>=(const Balance& s) const noexcept { return !operator<(s); }

    std::string string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& stream, const Balance& s);

    void swap(Balance& s) noexcept
    {
        using std::swap;
        swap(currency, s.currency);
        swap(amount, s.amount);
    }

    friend void swap(Balance& s1, Balance& s2) noexcept
    {
        s1.swap(s2);
    }
};

inline std::ostream& operator<<(std::ostream& stream, const Balance& s)
{
    stream << "Balance(";
    stream << "currency="; stream << "\"" << s.currency << "\"";
    stream << ",amount="; stream << s.amount;
    stream << ")";
    return stream;
}

} // namespace domain

namespace FBE {

template <class TBuffer>
class FieldModel<TBuffer, Balance>
{
public:
    FieldModel(TBuffer& buffer, size_t offset) noexcept : _buffer(buffer), _offset(offset)
        , currency(buffer, 4 + 4)
        , amount(buffer, currency.fbe_offset() + currency.fbe_size())
    {}

    // Get the field type
    size_t fbe_type() const noexcept { return 2; }
    // Get the field offset
    size_t fbe_offset() const noexcept { return _offset; }
    // Get the field size
    size_t fbe_size() const noexcept { return 4; }
    // Get the field body size
    size_t fbe_body() const noexcept
    {
        size_t fbe_result = 4 + 4
            + currency.fbe_size()
            + amount.fbe_size()
            ;
        return fbe_result;
    }
    // Get the field extra size
    size_t fbe_extra() const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4) > _buffer.size())
            return 0;

        _buffer.shift(fbe_struct_offset);

        size_t fbe_result = fbe_body()
            + currency.fbe_extra()
            + amount.fbe_extra()
            ;

        _buffer.unshift(fbe_struct_offset);

        return fbe_result;
    }

    // Shift the current field offset
    void fbe_shift(size_t size) noexcept { _offset += size; }
    // Unshift the current field offset
    void fbe_unshift(size_t size) noexcept { _offset -= size; }

    // Check if the struct value is valid
    bool verify(bool verify_type = true) const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return true;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4 + 4) > _buffer.size())
            return false;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset));
        if (fbe_struct_size < 4 + 4)
            return false;

        uint32_t fbe_struct_type = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset + 4));
        if (verify_type && (fbe_struct_type != fbe_type()))
            return false;

        _buffer.shift(fbe_struct_offset);
        bool fbe_result = verifyFields(fbe_struct_size);
        _buffer.unshift(fbe_struct_offset);
        return fbe_result;
    }

    // Check if the struct fields are valid
    bool verifyFields(size_t fbe_struct_size) const noexcept
    {
        size_t fbe_current_size = 4 + 4;

        if ((fbe_current_size + currency.fbe_size()) > fbe_struct_size)
            return true;
        if (!currency.verify())
            return false;
        fbe_current_size += currency.fbe_size();

        if ((fbe_current_size + amount.fbe_size()) > fbe_struct_size)
            return true;
        if (!amount.verify())
            return false;
        fbe_current_size += amount.fbe_size();

        return true;
    }

    // Get the struct value (begin phase)
    size_t get_begin() const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4 + 4) > _buffer.size())
            return 0;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset));
        assert((fbe_struct_size >= 4 + 4) && "Model is broken!");
        if (fbe_struct_size < 4 + 4)
            return 0;

        _buffer.shift(fbe_struct_offset);
        return fbe_struct_offset;
    }

    // Get the struct value (end phase)
    void get_end(size_t fbe_begin) const noexcept
    {
        _buffer.unshift(fbe_begin);
    }

    // Get the struct value
    void get(Balance& value) const noexcept
    {
        size_t fbe_begin = get_begin();
        if (fbe_begin == 0)
            return;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset()));

        getFields(value, fbe_struct_size);

        get_end(fbe_begin);
    }

    // Get the struct fields values
    void getFields(Balance& value, size_t fbe_struct_size) const noexcept
    {
        size_t fbe_current_size = 4 + 4;

        if ((fbe_current_size + currency.fbe_size()) <= fbe_struct_size)
            currency.get(value.currency);
        fbe_current_size += currency.fbe_size();

        if ((fbe_current_size + amount.fbe_size()) <= fbe_struct_size)
            amount.get(value.amount, (double)0.0);
        else
            value.amount = (double)0.0;
        fbe_current_size += amount.fbe_size();
    }

    // Set the struct value (begin phase)
    size_t set_begin()
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_size = (uint32_t)fbe_body();
        uint32_t fbe_struct_offset = (uint32_t)(_buffer.allocate(fbe_struct_size) - _buffer.offset());

        assert(((_buffer.offset() + fbe_struct_offset + fbe_struct_size) <= _buffer.size()) && "Model is broken!");

        *((uint32_t*)(_buffer.data() + _buffer.offset() + _offset)) = fbe_struct_offset;
        *((uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset)) = fbe_struct_size;
        *((uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset + 4)) = (uint32_t)fbe_type();

        _buffer.shift(fbe_struct_offset);
        return fbe_struct_offset;
    }

    // Set the struct value (end phase)
    void set_end(size_t fbe_begin)
    {
        _buffer.unshift(fbe_begin);
    }

    // Set the struct value
    void set(const Balance& value) noexcept
    {
        size_t fbe_begin = set_begin();
        if (fbe_begin == 0)
            return;

        setFields(value);

        set_end(fbe_begin);
    }

    // Set the struct fields values
    void setFields(const Balance& value) noexcept
    {
        currency.set(value.currency);
        amount.set(value.amount);
    }

private:
    TBuffer& _buffer;
    size_t _offset;

public:
    FieldModel<TBuffer, std::string> currency;
    FieldModel<TBuffer, double> amount;
};

} // namespace FBE

namespace FBE {

template <class TBuffer>
class BalanceModel : public FBE::Model<TBuffer>
{
public:
    BalanceModel() : model(this->buffer(), 4) {}

    // Get the model type
    size_t fbe_type() const noexcept { return model.fbe_type(); }
    // Get the model size
    size_t fbe_size() const noexcept { return model.fbe_size() + model.fbe_extra(); }

    FieldModel<TBuffer, Balance> model;

    // Check if the current struct value is valid
    bool verify()
    {
        if ((this->buffer().offset() + model.fbe_offset() - 4) > this->buffer().size())
            return false;

        uint32_t fbe_full_size = *((const uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4));
        if (fbe_full_size < model.fbe_size())
            return false;

        return model.verify();
    }

    // Create a new model (begin phase)
    size_t create_begin()
    {
        size_t fbe_begin = this->allocate(4 + model.fbe_size());
        return fbe_begin;
    }

    // Create a new model (end phase)
    size_t create_end(size_t fbe_begin)
    {
        size_t fbe_end = this->buffer().size();

        uint32_t fbe_full_size = (uint32_t)(fbe_end - fbe_begin);
        *((uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4)) = fbe_full_size;
        return fbe_full_size;
    }

    // Serialize the struct value
    size_t serialize(const Balance& value)
    {
        size_t fbe_begin = create_begin();
        model.set(value);
        size_t fbe_full_size = create_end(fbe_begin);
        return fbe_full_size;
    }

    // Deserialize the struct value
    size_t deserialize(Balance& value) const noexcept
    {
        if ((this->buffer().offset() + model.fbe_offset() - 4) > this->buffer().size())
            return 0;

        uint32_t fbe_full_size = *((const uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4));
        assert((fbe_full_size >= model.fbe_size()) && "Model is broken!");
        if (fbe_full_size < model.fbe_size())
            return 0;

        model.get(value);

        return fbe_full_size;
    }

    // Mode to the next struct value
    void next(size_t prev) noexcept
    {
        model.fbe_shift(prev);
    }
};

} // namespace FBE

namespace domain {

struct Account
{
    int32_t id;
    std::string name;
    Balance wallet;
    std::vector<Order> orders;

    Account()
        : id()
        , name()
        , wallet()
        , orders()
    {}

    Account(int32_t arg_id, const std::string& arg_name, const Balance& arg_wallet, const std::vector<Order>& arg_orders)
        : id(arg_id)
        , name(arg_name)
        , wallet(arg_wallet)
        , orders(arg_orders)
    {}

    bool operator==(const Account& s) const noexcept
    {
        return (
            (id == s.id)
            );
    }
    bool operator!=(const Account& s) const noexcept { return !operator==(s); }
    bool operator<(const Account& s) const noexcept
    {
        if (id < s.id)
            return true;
        if (s.id < id)
            return false;
        return false;
    }
    bool operator<=(const Account& s) const noexcept { return operator<(s) || operator==(s); }
    bool operator>(const Account& s) const noexcept { return !operator<=(s); }
    bool operator>=(const Account& s) const noexcept { return !operator<(s); }

    std::string string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& stream, const Account& s);

    void swap(Account& s) noexcept
    {
        using std::swap;
        swap(id, s.id);
        swap(name, s.name);
        swap(wallet, s.wallet);
        swap(orders, s.orders);
    }

    friend void swap(Account& s1, Account& s2) noexcept
    {
        s1.swap(s2);
    }
};

inline std::ostream& operator<<(std::ostream& stream, const Account& s)
{
    stream << "Account(";
    stream << "id="; stream << s.id;
    stream << ",name="; stream << "\"" << s.name << "\"";
    stream << ",wallet="; stream << s.wallet;
    {
        bool first = true;
        stream << ",orders=[" << s.orders.size() << "][";
        for (auto const& it : s.orders)
        {
            stream << std::string(first ? "" : ",") << it;
            first = false;
        }
        stream << "]";
    }
    stream << ")";
    return stream;
}

} // namespace domain

namespace FBE {

template <class TBuffer>
class FieldModel<TBuffer, Account>
{
public:
    FieldModel(TBuffer& buffer, size_t offset) noexcept : _buffer(buffer), _offset(offset)
        , id(buffer, 4 + 4)
        , name(buffer, id.fbe_offset() + id.fbe_size())
        , wallet(buffer, name.fbe_offset() + name.fbe_size())
        , orders(buffer, wallet.fbe_offset() + wallet.fbe_size())
    {}

    // Get the field type
    size_t fbe_type() const noexcept { return 3; }
    // Get the field offset
    size_t fbe_offset() const noexcept { return _offset; }
    // Get the field size
    size_t fbe_size() const noexcept { return 4; }
    // Get the field body size
    size_t fbe_body() const noexcept
    {
        size_t fbe_result = 4 + 4
            + id.fbe_size()
            + name.fbe_size()
            + wallet.fbe_size()
            + orders.fbe_size()
            ;
        return fbe_result;
    }
    // Get the field extra size
    size_t fbe_extra() const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4) > _buffer.size())
            return 0;

        _buffer.shift(fbe_struct_offset);

        size_t fbe_result = fbe_body()
            + id.fbe_extra()
            + name.fbe_extra()
            + wallet.fbe_extra()
            + orders.fbe_extra()
            ;

        _buffer.unshift(fbe_struct_offset);

        return fbe_result;
    }

    // Shift the current field offset
    void fbe_shift(size_t size) noexcept { _offset += size; }
    // Unshift the current field offset
    void fbe_unshift(size_t size) noexcept { _offset -= size; }

    // Check if the struct value is valid
    bool verify(bool verify_type = true) const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return true;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4 + 4) > _buffer.size())
            return false;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset));
        if (fbe_struct_size < 4 + 4)
            return false;

        uint32_t fbe_struct_type = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset + 4));
        if (verify_type && (fbe_struct_type != fbe_type()))
            return false;

        _buffer.shift(fbe_struct_offset);
        bool fbe_result = verifyFields(fbe_struct_size);
        _buffer.unshift(fbe_struct_offset);
        return fbe_result;
    }

    // Check if the struct fields are valid
    bool verifyFields(size_t fbe_struct_size) const noexcept
    {
        size_t fbe_current_size = 4 + 4;

        if ((fbe_current_size + id.fbe_size()) > fbe_struct_size)
            return true;
        if (!id.verify())
            return false;
        fbe_current_size += id.fbe_size();

        if ((fbe_current_size + name.fbe_size()) > fbe_struct_size)
            return true;
        if (!name.verify())
            return false;
        fbe_current_size += name.fbe_size();

        if ((fbe_current_size + wallet.fbe_size()) > fbe_struct_size)
            return true;
        if (!wallet.verify())
            return false;
        fbe_current_size += wallet.fbe_size();

        if ((fbe_current_size + orders.fbe_size()) > fbe_struct_size)
            return true;
        if (!orders.verify())
            return false;
        fbe_current_size += orders.fbe_size();

        return true;
    }

    // Get the struct value (begin phase)
    size_t get_begin() const noexcept
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_offset = *((const uint32_t*)(_buffer.data() + _buffer.offset() + _offset));
        if ((_buffer.offset() + fbe_struct_offset + 4 + 4) > _buffer.size())
            return 0;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset));
        assert((fbe_struct_size >= 4 + 4) && "Model is broken!");
        if (fbe_struct_size < 4 + 4)
            return 0;

        _buffer.shift(fbe_struct_offset);
        return fbe_struct_offset;
    }

    // Get the struct value (end phase)
    void get_end(size_t fbe_begin) const noexcept
    {
        _buffer.unshift(fbe_begin);
    }

    // Get the struct value
    void get(Account& value) const noexcept
    {
        size_t fbe_begin = get_begin();
        if (fbe_begin == 0)
            return;

        uint32_t fbe_struct_size = *((const uint32_t*)(_buffer.data() + _buffer.offset()));

        getFields(value, fbe_struct_size);

        get_end(fbe_begin);
    }

    // Get the struct fields values
    void getFields(Account& value, size_t fbe_struct_size) const noexcept
    {
        size_t fbe_current_size = 4 + 4;

        if ((fbe_current_size + id.fbe_size()) <= fbe_struct_size)
            id.get(value.id);
        fbe_current_size += id.fbe_size();

        if ((fbe_current_size + name.fbe_size()) <= fbe_struct_size)
            name.get(value.name);
        fbe_current_size += name.fbe_size();

        if ((fbe_current_size + wallet.fbe_size()) <= fbe_struct_size)
            wallet.get(value.wallet);
        fbe_current_size += wallet.fbe_size();

        if ((fbe_current_size + orders.fbe_size()) <= fbe_struct_size)
            orders.get(value.orders);
        fbe_current_size += orders.fbe_size();
    }

    // Set the struct value (begin phase)
    size_t set_begin()
    {
        if ((_buffer.offset() + _offset + fbe_size()) > _buffer.size())
            return 0;

        uint32_t fbe_struct_size = (uint32_t)fbe_body();
        uint32_t fbe_struct_offset = (uint32_t)(_buffer.allocate(fbe_struct_size) - _buffer.offset());

        assert(((_buffer.offset() + fbe_struct_offset + fbe_struct_size) <= _buffer.size()) && "Model is broken!");

        *((uint32_t*)(_buffer.data() + _buffer.offset() + _offset)) = fbe_struct_offset;
        *((uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset)) = fbe_struct_size;
        *((uint32_t*)(_buffer.data() + _buffer.offset() + fbe_struct_offset + 4)) = (uint32_t)fbe_type();

        _buffer.shift(fbe_struct_offset);
        return fbe_struct_offset;
    }

    // Set the struct value (end phase)
    void set_end(size_t fbe_begin)
    {
        _buffer.unshift(fbe_begin);
    }

    // Set the struct value
    void set(const Account& value) noexcept
    {
        size_t fbe_begin = set_begin();
        if (fbe_begin == 0)
            return;

        setFields(value);

        set_end(fbe_begin);
    }

    // Set the struct fields values
    void setFields(const Account& value) noexcept
    {
        id.set(value.id);
        name.set(value.name);
        wallet.set(value.wallet);
        orders.set(value.orders);
    }

private:
    TBuffer& _buffer;
    size_t _offset;

public:
    FieldModel<TBuffer, int32_t> id;
    FieldModel<TBuffer, std::string> name;
    FieldModel<TBuffer, Balance> wallet;
    FieldModelArray<TBuffer, Order> orders;
};

} // namespace FBE

namespace FBE {

template <class TBuffer>
class AccountModel : public FBE::Model<TBuffer>
{
public:
    AccountModel() : model(this->buffer(), 4) {}

    // Get the model type
    size_t fbe_type() const noexcept { return model.fbe_type(); }
    // Get the model size
    size_t fbe_size() const noexcept { return model.fbe_size() + model.fbe_extra(); }

    FieldModel<TBuffer, Account> model;

    // Check if the current struct value is valid
    bool verify()
    {
        if ((this->buffer().offset() + model.fbe_offset() - 4) > this->buffer().size())
            return false;

        uint32_t fbe_full_size = *((const uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4));
        if (fbe_full_size < model.fbe_size())
            return false;

        return model.verify();
    }

    // Create a new model (begin phase)
    size_t create_begin()
    {
        size_t fbe_begin = this->allocate(4 + model.fbe_size());
        return fbe_begin;
    }

    // Create a new model (end phase)
    size_t create_end(size_t fbe_begin)
    {
        size_t fbe_end = this->buffer().size();

        uint32_t fbe_full_size = (uint32_t)(fbe_end - fbe_begin);
        *((uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4)) = fbe_full_size;
        return fbe_full_size;
    }

    // Serialize the struct value
    size_t serialize(const Account& value)
    {
        size_t fbe_begin = create_begin();
        model.set(value);
        size_t fbe_full_size = create_end(fbe_begin);
        return fbe_full_size;
    }

    // Deserialize the struct value
    size_t deserialize(Account& value) const noexcept
    {
        if ((this->buffer().offset() + model.fbe_offset() - 4) > this->buffer().size())
            return 0;

        uint32_t fbe_full_size = *((const uint32_t*)(this->buffer().data() + this->buffer().offset() + model.fbe_offset() - 4));
        assert((fbe_full_size >= model.fbe_size()) && "Model is broken!");
        if (fbe_full_size < model.fbe_size())
            return 0;

        model.get(value);

        return fbe_full_size;
    }

    // Mode to the next struct value
    void next(size_t prev) noexcept
    {
        model.fbe_shift(prev);
    }
};

} // namespace FBE
