<?php
/*
	@! project #tutorials (functions.php)
	@@package: as_tutorials
*/

## Clean the references mentioned in the introduction text.
function clean_input($input) {
	$search = array('[1]', '[2]', '[3]', '[4]', '[5]', '[6]', '[7]', '[8]', '[9]', '[10]');

	$output = str_replace($search, '', $input);
	return $output;
}

/*
	@@ For fetching the introduction text from any Wikipedia page.
	We are using preg_match_all function to fetch all the text after the closing </table> tag and before the opening
	<div id="toc" class="toc"> DIV tag. We are doing so becase the introduction text is contained between these
	only as per the current Wikipedia markup.
*/
function get_text($html) {
	preg_match_all('/<\/table>(.*?)<div id="toc" class="toc">/s', $html, $matches);
		if($matches) {
			return $matches[1][0];
		} else {
			return 'There seems to be an error while fetching the data.';
		}
}