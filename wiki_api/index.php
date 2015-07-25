<?php
/*
	@! A basic Wikipedia scraper
-----------------------------------------------------------------------------	
	# author: @akshitsethi
	# web: http://www.akshitsethi.me
	# email: ping@akshitsethi.me
	# mobile: (91)9871084893
-----------------------------------------------------------------------------
	@@ The biggest failure is failing to try.
*/

include('php/functions.php');

?>
<!doctype html>
<html lang="en">
<head>
<title>Basic Wikipedia scraper - A tutorial by akshitsethi.me</title>
<meta http-equiv="Content-type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta name="Description" content="Learn to scrap basic information from Wikipedia using PHP." />
<meta name="Keywords" content="scraper, wikipedia scraper, wiki scraper, php scraper, akshitsethi" />
<meta name="Owner" content="Akshit Sethi" />
<link rel="shortcut icon" href="img/favicon.ico">
<link href="css/style.css" media="screen" rel="stylesheet" type="text/css" />
</head>
<body>
	<div class="header">
		<div class="header-inner clearfix">
			<div class="pull-left">
				<a href="http://www.akshitsethi.me" target="_blank"><img src="img/logo.png" class="logo"></a>
			</div>

			<div class="pull-right">
				<p class="small-text no-margin"><span class="highlight">PHP <strong>Wikipedia</strong> scraper</span></p>
			</div>
		</div>
	</div>

	<div class="container">
		<div class="page-header">
			<h1>Implementation of Wikipedia scraper using PHP</h1>
			<p>Wikipedia is the hub of information. No matter what information you looking for, you are surely going to get in on the website. Have a look at the demo below which fetches basic information for <i>Pamela Anderson</i> from Wikipedia.</p>
		</div>
<?php

## About to start the scrapping from this point
$url = 'http://en.wikipedia.org/wiki/Pamela_Anderson';
$html = file_get_contents($url);

$info = get_text($html);

## Cleaning the fetched description tag
$info = strip_tags($info);
$info = clean_input($info);

echo '<span class="highlight strong">Pamela Anderson</span>';
echo '<p style="line-height: 18px;">'.$info.'</p>';

## Clear the parser
$info = null;
$html = null;

?>
		<div class="page-footer">
			<p>A small piece of code by <strong><a href="http://www.akshitsethi.me" target="_blank">Akshit Sethi</a></strong></p>
		</div>
	</div>
</body>
</html>