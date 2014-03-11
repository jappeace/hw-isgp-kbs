#include "Animation.h"

namespace isgp {

	Animation::Animation(const string path, Size& frameSize, int frameCount, int frameTime) {
		this->_path = path;
		this->_frame_count = frameCount;
		this->_frame_size = frameSize;
		this->_frame_time = frameTime;

		this->_current_frame = 0;
		this->_current_frame_time = 0;
	}

	Animation::Animation() {
	}

	Animation::~Animation(void) {
	}

	void Animation::OnUpdate(const double tpf) {
		this->_current_frame_time += tpf;
		while (this->_current_frame_time >= this->_frame_time) {
			this->_current_frame_time -= this->_frame_time;
			this->_current_frame++;

			if (this->_current_frame >= this->_frame_count) {
				this->_current_frame = 0;
			}
		}
	}

	void Animation::Reset() {
		this->_current_frame = 0;
		this->_current_frame_time = 0;
	}

	void Animation::Render(Graphics* g, Vector2D& position) {
		this->Render(g, position, Vector2D(0, 0));
	}

	void Animation::Render(Graphics* g, Vector2D& position, Vector2D& offset) {
		Vector2D frameOffset = Vector2D(this->_current_frame * this->_frame_size.GetWidth(), 0);
		Vector2D totalOffset = offset + frameOffset;

		g->DrawBitmap(this->_path, position, totalOffset, this->_frame_size);
	}

}
