using System.Collections.Generic;

namespace LevelEditor.Models
{
	/// <summary>
	/// The behaviour of a gridobject with conditions and actions.
	/// </summary>
	public class Behaviour
	{
		/// <summary>
		/// All conditions that must be true for the actions to be executed.
		/// </summary>
		public IEnumerable<Condition> Conditions { get; set; }

		/// <summary>
		/// Actions that will be executed if all conditions are true.
		/// </summary>
		public IEnumerable<Action> Actions { get; set; }

		public Behaviour()
		{
			Conditions = new List<Condition>();
			Actions = new List<Action>();
		}
	}
}
