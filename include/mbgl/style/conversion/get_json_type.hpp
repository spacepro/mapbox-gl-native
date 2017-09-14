#pragma once

#include <string>

namespace mbgl {
namespace style {
namespace conversion {

template <class V>
std::string getJSONType(const V& value) {
    using namespace mbgl::style::conversion;
    
    if (isUndefined(value)) {
        return "null";
    }
    if (isArray(value)) {
        return "array";
    }
    if (isObject(value)) {
        return "object";
    }
    optional<mbgl::Value> v = toValue(value);

    // Since we've already checked the non-atomic types above, value must then
    // be a string, number, or boolean -- thus, assume that the toValue()
    // conversion succeeds.
    assert(v);

    return v->match(
        [&] (const std::string&) { return "string"; },
        [&] (bool) { return "boolean"; },
        [&] (auto) { return "number"; }
    );
}

} // namespace conversion
} // namespace style
} // namespace mbgl
