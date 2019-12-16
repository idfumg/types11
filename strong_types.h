#pragma once

#include <string>
#include <iostream>

#define declare_type(class_name, data_type)                                                    \
    class class_name final {                                                                   \
    public:                                                                                    \
        ~class_name() noexcept = default;                                                      \
        explicit class_name() = default;                                                       \
        template<class... T> explicit class_name(T&& ...arg) : val(std::forward<T>(arg)...) {} \
        class_name(const class_name& arg) = default;                                           \
        class_name(class_name&& arg) = default;                                                \
        class_name& operator=(const class_name& arg) = default;                                \
        class_name& operator=(class_name&& arg) = default;                                     \
        bool operator==(const class_name& rhs) const {return val == rhs.val;}                  \
        bool operator!=(const class_name& rhs) const {return not operator==(rhs); }            \
        const data_type& value() const noexcept { return val; }                                \
        data_type& value() noexcept { return val; }                                            \
                                                                                               \
    private:                                                                                   \
        data_type val {};                                                                      \
    };

#define declare_string(class_name)                                          \
    class class_name final {                                                \
    public:                                                                 \
        ~class_name() noexcept = default;                                   \
        explicit class_name() = default;                           \
        template<class... T> explicit class_name(T&& ...arg) : val(std::forward<T>(arg)...) {} \
        class_name(const class_name& arg) = default;                        \
        class_name(class_name&& arg) noexcept = default;                    \
        class_name& operator=(const class_name& arg) = default;             \
        class_name& operator=(class_name&& arg) noexcept = default;         \
        bool operator==(const class_name& rhs) const noexcept{return val == rhs.val; } \
        bool operator!=(const class_name& rhs) const noexcept{return not operator==(rhs); } \
        bool operator<(const class_name& rhs) const noexcept{return val < rhs.val; } \
        std::ostream& operator<<(std::ostream& out) {return out << val;} \
        const std::string& value() const noexcept { return val; }           \
        std::string& value() noexcept { return val; }                       \
        bool empty() const noexcept { return val.empty(); }                 \
                                                                            \
    private:                                                                \
        std::string val {};                                                 \
    };

#define declare_number(class_name, int_t)                                   \
    class class_name final {                                                \
    public:                                                                 \
        ~class_name() noexcept = default;                                   \
        constexpr explicit class_name() noexcept = default;                           \
        constexpr explicit class_name(const int_t arg) noexcept : val(arg) {}         \
        constexpr class_name(const class_name& arg) noexcept = default;               \
        constexpr class_name(class_name&& arg) noexcept = default;                    \
        constexpr class_name& operator=(const class_name& arg) noexcept = default;    \
        constexpr class_name& operator=(class_name&& arg) noexcept = default;         \
        constexpr bool operator==(const class_name& rhs) const noexcept{return val == rhs.val; } \
        constexpr bool operator!=(const class_name& rhs) const noexcept{return not operator==(rhs); } \
        constexpr bool operator<(const class_name& rhs) const noexcept{return val < rhs.val; } \
        std::ostream& operator<<(std::ostream& out) {return out << val;} \
        constexpr int_t value() const noexcept { return val; }                 \
        constexpr int_t& value() noexcept { return val; }                             \
                                                                            \
    private:                                                                \
        int_t val {};                                                       \
    };

#define declare_bool(class_name)                                            \
    class class_name final {                                                \
    public:                                                                 \
        ~class_name() noexcept = default;                                   \
        constexpr explicit class_name() noexcept = default;                           \
        constexpr explicit class_name(const bool arg) noexcept : val(arg) {}          \
        constexpr class_name(const class_name& arg) noexcept = default;               \
        constexpr class_name(class_name&& arg) noexcept = default;                    \
        constexpr class_name& operator=(const class_name& arg) noexcept = default;    \
        constexpr class_name& operator=(class_name&& arg) noexcept = default;         \
        constexpr bool operator==(const class_name& rhs) const noexcept{return val == rhs.val; } \
        constexpr bool operator!=(const class_name& rhs) const noexcept{return not operator==(rhs); } \
        constexpr bool operator<(const class_name& rhs) const noexcept{return val < rhs.val; } \
        std::ostream& operator<<(std::ostream& out) {return out << val;} \
        constexpr operator bool() const noexcept {return val;}                        \
        constexpr bool value() const noexcept {return val; }                   \
        constexpr bool& value() noexcept {return val; }                               \
                                                                            \
    private:                                                                \
        bool val { false };                                                 \
    };

#define declare_stream(class_name)                                       \
    inline std::ostream& operator<<(std::ostream& out, const class_name& param) { \
        return out << param.value();                                    \
    }

#define declare_less(class_name)                                       \
    inline bool operator<(const class_name& param1, const class_name& param2) { \
        return param1.value() < param2.value();                           \
    }
