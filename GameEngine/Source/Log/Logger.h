#include<spdlog/spdlog.h>

namespace GME {
	class Logger {
	public:
		void setLogLevel(spdlog::level::level_enum level);
		const std::shared_ptr<spdlog::logger>& getEngineLogger() const;
		const std::shared_ptr<spdlog::logger>& getGameLogger() const;

		static inline Logger& getLoggerInstance() {
			static Logger s_instance ;
			return s_instance;
		}
	private:
		Logger();
		~Logger() = default;
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;

	private:
		std::shared_ptr<spdlog::logger> engineLogger;
		std::shared_ptr<spdlog::logger> gameLogger;
	};
}


#define GME_ENGINE_TRACE(...)     ::GME::Logger::getLoggerInstance().getEngineLogger()->trace(__VA_ARGS__)
#define GME_ENGINE_INFO(...)      ::GME::Logger::getLoggerInstance().getEngineLogger()->info(__VA_ARGS__)
#define GME_ENGINE_WARN(...)      ::GME::Logger::getLoggerInstance().getEngineLogger()->warn(__VA_ARGS__)
#define GME_ENGINE_ERROR(...)     ::GME::Logger::getLoggerInstance().getEngineLogger()->error(__VA_ARGS__)
#define GME_ENGINE_CRITICAL(...)  ::GME::Logger::getLoggerInstance().getEngineLogger()->critical(__VA_ARGS__)

#define GAME_TRACE(...)           ::GME::Logger::getLoggerInstance().getGameLogger()->trace(__VA_ARGS__)
#define GAME_INFO(...)            ::GME::Logger::getLoggerInstance().getGameLogger()->info(__VA_ARGS__)
#define GAME_WARN(...)            ::GME::Logger::getLoggerInstance().getGameLogger()->warn(__VA_ARGS__)
#define GAME_ERROR(...)           ::GME::Logger::getLoggerInstance().getGameLogger()->error(__VA_ARGS__)
#define GAME_CRITICAL(...)        ::GME::Logger::getLoggerInstance().getGameLogger()->critical(__VA_ARGS__)

