// Time.hpp
//
//

#pragma once

#include <functional>
#include <thread>
#include <memory>
#include <chrono>

#include "../Misc/Misc.hpp"
#ifdef CPP20GRT
#define nodiscarderr [[nodiscard("store the return value, otherwise the function will not work")]]
#else
#define nodiscarderr [[nodiscard]]
#endif

namespace {
	template<typename F, typename... Args>
	void SetTimeout__(F&& func, const uint32_t timeout, const bool async, Args&&... args) noexcept {
		const auto function = [&func, timeout,
#ifdef CPP20GRT
			&...args = std::forward<Args>(args)
#else
			& args...
#endif
		]() {
			Moon::Misc::Sleep(timeout);
			func(std::forward<Args>(args)...);
		};

		async ? std::thread(function, std::forward<Args>(args)...).detach() : function(std::forward<Args>(args)...);
	}
}

namespace Moon {
	namespace Time {
		template<typename F, typename... Args>
		class Interval {
		public:
			explicit Interval(const F& func, const uint32_t timeout, const bool async, Args&&... args) noexcept
				: m_Func(func), m_Timeout(timeout), m_Async(async) {

				const auto function = [&]() {
					for (;;) {
						Moon::Misc::Sleep(m_Timeout);

						if (m_Running == 1)
							m_Func(std::forward<Args>(args)...);
						else if (m_Running == -1)
							break;
					}
				};

				m_Async ? std::thread(function, std::forward<Args>(args)...).detach() : function(std::forward<Args>(args)...);
			}

			~Interval() = default;

			void Pause(void) noexcept {
				m_Running = 0;
			}

			void Continue(void) noexcept {
				m_Running = 1;
			}

			void Stop(void) noexcept {
				m_Running = -1;
			}
		private:
			int32_t m_Running = 1;
			uint32_t m_Timeout = 1000;
			F m_Func;
			bool m_Async = true;
		};

		template<typename F, typename... Args>
		void SetTimeoutAsync(F&& func, const uint32_t timeout, Args&&... args) noexcept {
			SetTimeout__(func, timeout, true, args...);
		}

		template<typename F, typename... Args>
		void SetTimeoutSync(F&& func, const uint32_t timeout, Args&&... args) noexcept {
			SetTimeout__(func, timeout, false, args...);
		}

		template<typename F, typename... Args>
		nodiscarderr std::unique_ptr<Interval<F, Args...>> SetIntervalAsync(F&& func, const uint32_t timeout, Args&&... args) noexcept {
			return std::make_unique<Interval<F, Args...>>(func, timeout, std::forward<Args>(args)..., true);
		}

		template<typename F, typename... Args>
		nodiscarderr std::unique_ptr<Interval<F, Args...>> SetIntervalSync(F&& func, const uint32_t timeout, Args&&... args) noexcept {
			return std::make_unique<Interval<F, Args...>>(func, timeout, std::forward<Args>(args)..., false);
		}
	}
}