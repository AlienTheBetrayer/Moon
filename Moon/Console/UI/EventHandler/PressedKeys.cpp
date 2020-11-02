#include "PressedKeys.hpp"

PressedKeys::PressedKeys(const std::vector<uint8_t>& keys) noexcept
{
	m_PressedKeys = keys;
}

bool PressedKeys::Contains(const uint8_t key) const noexcept
{
	return std::find(m_PressedKeys.begin(), m_PressedKeys.end(), key) != m_PressedKeys.end();
}
