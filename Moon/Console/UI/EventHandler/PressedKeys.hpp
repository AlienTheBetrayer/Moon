#pragma once

#include <cstdint>
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