template <char ...c> struct TString { };

template <typename T, T ...str>
constexpr TString<str...> operator""_s()
{
    return {};
}

template <char ...lc, char ...rc>
constexpr TString<lc..., rc...>
operator+(const TString<lc...>& l, const TString<rc...>& r)
{
    return {};
}

template <char ...lc, char ...rc>
constexpr bool operator==(const TString<lc...>& l, const TString<rc...>& r)
{
    char lstr[] = {lc...};
    char rstr[] = {rc...};
    if (sizeof...(lc) != sizeof...(rc)) return false;
    for (unsigned i = 0; i < sizeof...(lc); i++)
        if (lstr[i] != rstr[i]) return false;
    return true;
}

int main()
{
    constexpr auto hello = "hello"_s + " world"_s;
    static_assert(hello == "hello world"_s);
    return 0;
}
