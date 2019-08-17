intrinsic class TextFormat
{
	var align: String;
	var blockIndent: Number;
	var bold: Boolean;
	var bullet: Boolean;
	var color: Number;
	var font: String;
	var indent: Number;
	var italic: Boolean;
	var kerning: Boolean;
	var leading: Number;
	var leftMargin: Number;
	var letterSpacing: Number;
	var rightMargin: Number;
	var size: Number;
	var tabStops: Array;
	var target: String;
	var underline: Boolean;
	var url: String;

	function TextFormat(font: String, size: Number, color: Number,
                    	bold: Boolean, italic: Boolean, underline: Boolean,
                    	url: String, target: String, align: String,
                    	leftMargin: Number, rightMargin: Number, indent: Number, leading: Number);

	function getTextExtent(text: String, width: Number): Object;
	
	// GFx Extensions
	var alpha: Number;
}
