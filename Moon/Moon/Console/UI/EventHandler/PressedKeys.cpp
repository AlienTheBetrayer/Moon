// PressedKeys.cpp

#include "PressedKeys.hpp"

PressedKeys::PressedKeys(const std::vector<uint8_t>& keys) noexcept
{
	m_PressedKeys = keys;
}

[[nodiscard]] CPP20CONSTEXPR bool PressedKeys::Contains(const uint8_t key) const noexcept
{
	return std::find(m_PressedKeys.begin(), m_PressedKeys.end(), std::toupper(key)) != m_PressedKeys.end();
}
