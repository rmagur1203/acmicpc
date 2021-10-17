param(
    [int]$in = (Read-Host "program number")
)
$parent = "9999"
if ($in -gt 19999) {
    $parent = "29999"
}
elseif ($in -gt 9999) {
    $parent = "19999"
}

if (Test-Path -Path "$parent\\$in.c" -PathType Leaf){
    gcc.exe -g "$parent\\$in.c" -o "$parent\\$in.exe"
}
if (Test-Path -Path "$parent\\$in.cpp" -PathType Leaf){
    g++.exe -g "$parent\\$in.cpp" -o "$parent\\$in.exe"
}

if (Test-Path -Path "$parent\\$in.test" -PathType Leaf){
    Get-Content "$parent\\$in.test" | & "$parent\\$in.exe"
}
else{
    & "$parent\\$in.exe"
}