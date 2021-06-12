/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Animation.h
Project: GAM150_Networker
Author: Team RETRY - Yujin Park / Yeongju Lee / Haeun Park
Creation date: 06/03/2021
-----------------------------------------------------------------*/
#pragma once
#include <vector>
#include <filesystem>

namespace Retry
{
	class Animation
	{
	public:
		Animation();
		Animation(const std::filesystem::path& fileName);
		~Animation();
		void Update(double dt);
		int GetDisplayFrame();
		void ResetAnimation();
		bool IsAnimationDone();
	private:
		enum class Command {
			PlayFrame,
			Loop,
			End,
		};
		class CommandData {
		public:
			virtual ~CommandData() {}
			virtual Command GetType() = 0;
		};
		class PlayFrame : public CommandData {
		public:
			PlayFrame(int frame, double duration);
			virtual Command GetType() override { return Command::PlayFrame; }
			void Update(double dt);
			bool IsFrameDone();
			void ResetTime();
			int GetFrameNum();
		private:
			int frame;
			double targetTime;
			double timer;
		};
		class Loop : public CommandData {
		public:
			Loop(int loopToIndex);
			virtual Command GetType() override { return Command::Loop; }
			int GetLoopToIndex();
		private:
			int loopToIndex;
		};
		class End : public CommandData {
		public:
			virtual Command GetType() override { return Command::End; }
		private:
		};

		bool isAnimationDone;
		int animSequenceIndex;
		PlayFrame* currPlayFrameData;
		std::vector<CommandData*> animation;
	};
}