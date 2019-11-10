#pragma once

template<class T>
class Singleton
{
public:
	static T& Get()
	{
		static MemGuard g; // clean up on program end
		if (!m_instance) {
			m_instance = new T();
		}
		return *m_instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator= (const Singleton) = delete;

protected:
	Singleton() { };
	virtual ~Singleton() { }

private:
	inline static T* m_instance = nullptr;

	class MemGuard {
	public:
		~MemGuard() {
			delete m_instance;
			m_instance = nullptr;
		}
	};
};
