﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevelEditor.Models
{
	/// <summary>
	/// Singleton that keeps the bitmap for every tiletype.
	/// </summary>
	class BitmapCollection
	{
		/// <summary>
		/// Singleton instance with lazy loading.
		/// </summary>
		public static BitmapCollection Instance
		{
			get
			{
				if (_instance == null)
				{
					_instance = new BitmapCollection();
				}
				return _instance;
			}
		}

		/// <summary>
		/// Dictionary of bitmap per tiletype.
		/// </summary>
		public IDictionary<GridObjectType, Bitmap> BitmapDictionary { get; set; }

		private static BitmapCollection _instance;
		private const string SpritesFolder = @"sprites\";

		/// <summary>
		/// Private constructor for singleton.
		/// </summary>
		private BitmapCollection()
		{
			BitmapDictionary = new Dictionary<GridObjectType, Bitmap>();
			string fileName;
			foreach (GridObjectType tileType in Enum.GetValues(typeof(GridObjectType)))
			{
				fileName = string.Format("{0}{1}.bmp",
					SpritesFolder, Enum.GetName(typeof(GridObjectType), tileType));
				BitmapDictionary.Add(tileType, (Bitmap)Bitmap.FromFile(fileName));
			}
		}

		/// <summary>
		/// Gets the bitmap for the specified tiletype.
		/// </summary>
		public static Bitmap GetBitmapForType(GridObjectType type)
		{
			return Instance.BitmapDictionary[type];
		}
	}
}
