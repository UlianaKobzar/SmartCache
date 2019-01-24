#pragma once
#include <unordered_map>
#include <mutex>
#include <condition_variable>

template<typename ID, typename TObject, typename TFactory>
class SmartCache {
private:
	using ptr_obj = std::shared_ptr<TObject>;

	std::unordered_map<ID, std::weak_ptr<TObject>> cache_;
	TFactory factory_;

	ptr_obj get_obj_by_id_(ID id) {

		//critical section
		//lock_guard ?
		ptr_obj object = cache_[id].lock();

		if (object == nullptr)
		{
			object = ptr_obj(factory_(id));
			cache_[id] = object;
		}
		//critical section

		return object;
	}

public:
	SmartCache(TFactory factory) : factory_(factory) {}

	ptr_obj operator[] (ID id) {
		return get_obj_by_id_(id);
	}

	ptr_obj get_obj_by_id(ID id) {
		return get_obj_by_id_(id);
	}

};

//Wrapper<TObject>