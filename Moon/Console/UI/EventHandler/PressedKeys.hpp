// PressedKeys.hpp
//
// A simple class that is used in the EventArgs in the EventHandler when you hook the KeyPressedWithin or such events

#pragma once

#include <cstdint>
#include <cctype>
#include <vector>

class PressedKeys
{
public:
	PressedKeys(void) noexcept = default;
	PressedKeys(const std::vector<uint8_t>& keys) noexcept;

	bool Contains(const uint8_t key) const noexcept;

	~PressedKeys(void) noexcept = default;
private:
	std::vector<uint8_t> m_PressedKeys;
};