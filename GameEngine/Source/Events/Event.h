#pragma once

namespace GME {

    enum EventCategory {
        EventCategoryUnknown = 0,
        EventCategoryApplication = 1,
        EventCategoryInput = 2,
        EventCategoryKeyboard = 4,
        EventCategoryMouse = 8
    };

    enum class EventType {
        Unknown,
        WindowClosed,
        WindowResized,
        WindowMoved,
        WindowFocusGained,
        WindowFocusLost,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseScrolled,
        MouseMoved
    };

    class Event {
    public:
        virtual ~Event() = default;
        virtual EventType getType() const = 0;
        virtual int getCategoryFlags() const = 0;

        bool handled = false;

    protected:
        Event() = default;
    };

    class WindowClosedEvent : public Event {
    public:
        static constexpr EventType TYPE = EventType::WindowClosed;
        static constexpr int CATEGORY = EventCategoryApplication;

        EventType getType() const override { return TYPE; }
        int getCategoryFlags() const override { return CATEGORY; }
    };

    class WindowResizedEvent : public Event {
    public:
        static constexpr EventType TYPE = EventType::WindowResized;
        static constexpr int CATEGORY = EventCategoryApplication;

        WindowResizedEvent(int width, int height)
            : m_width(width),
              m_height(height) {
        }

        EventType getType() const override { return TYPE; }
        int getCategoryFlags() const override { return CATEGORY; }

        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

    private:
        int m_width;
        int m_height;
    };

    class EventDispatcher {
    public:
        EventDispatcher(Event& event) : m_event(event) {}

        template<typename T, typename F>
        bool dispatch(const F& func) {
            if (m_event.getType() == T::TYPE) {
                m_event.handled |= func(static_cast<T&>(m_event));
                return true;
            }
            return false;
        }

    private:
        Event& m_event;
    };

}
