#pragma once
#include "Character.h"
#include "SurroundEnvironment.h"

namespace MovementFramework
{
	class JumpCalculator
	{
	public:
		JumpCalculator();

		/// <summary>
		/// Calculates the maximum jump height (in meters) using character's jump speed and environment's gravity.
		/// </summary>
		/// <param name="character">The character.</param>
		/// <param name="environment">The environment.</param>
		/// <returns>Returns float number as maximum height.</returns>
		static float calculateJumpHeight(Character & character, SurroundEnvironment & environment);

		/// <summary>
		/// Calculates the time of jump (from the moment of the jump, until the object touches the ground).
		/// Used character's speed and environment's gravity.
		/// </summary>
		/// <param name="character">The character.</param>
		/// <param name="environment">The environment.</param>
		/// <returns>The time of jump in seconds.</returns>
		static float calculateJumpTime(Character & character, SurroundEnvironment & environment);

		/// <summary>
		/// Determines whether the specified character is capable to jump on over passed height.
		/// </summary>
		/// <param name="character">The character.</param>
		/// <param name="environment">The environment.</param>
		/// <param name="heightToJump">The height to jump.</param>
		/// <returns></returns>
		static bool isCapableToJumpOn(Character & character, SurroundEnvironment & environment, float heightToJump);
	};
}