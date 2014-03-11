#pragma once

#include <string>
#include "Graphics.h"

namespace isgp {
	class Animation
	{
	public:
		// path: They path of the image
		// frameSize: Each frame has will be the given size.
		// frameCount: The amount of frames in the file (only horizontal frames)
		// frameTime: The time in milliseconds which defines how long a frame will be visible
		Animation(const string path, Size& frameSize, int frameCount, int frameTime);
		Animation(void);
		~Animation(void);

		// Updates the animation based on the time which has passed.
		void OnUpdate(const double tpf);

		// Renders the animation onto the screen at the given point
		void Render(Graphics* g, Point& position);

		// Renders the animation onto the screen at the given point
		// The given offset will be added to the animation calculated offset to
		// give better integration with tilesets.
		void Render(Graphics* g, Point& position, Point& offset);

		// Resets the animation to the first frame
		void Reset();

	private:
		// The path of the image we render
		string _path;
		// The amount of frames in the image
		int _frame_count;
		// The amount of milliseconds per frame
		int _frame_time;
		// The current number of the frame we render (zero based)
		int _current_frame;
		// The current amount of milliseconds spend on this frame
		double _current_frame_time;
		// The size of a single frame
		Size _frame_size;
	};
}
