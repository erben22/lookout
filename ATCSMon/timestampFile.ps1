# Flow:
#   - Watch directory for changes.
#   - Upon directory change, get changed filed.
#   - Get statistics on the file such as last modified/created time.
#   - Modify the file with a timestamp.
#   - Rename the file.
#   - Stage for syncing.
#   - Invoke winscp.

Function global:AddTextToImage {
    # Orignal code from http://www.ravichaganti.com/blog/?p=1012
    [CmdletBinding()]
    PARAM (
        [Parameter(Mandatory=$true)][String] $sourcePath,
        [Parameter(Mandatory=$true)][String] $destPath,
        [Parameter()][String] $Description
    )
 
    try {
        
        if (!(Test-Path $sourcePath -PathType Leaf))
        {
            throw "Invalid source path"
        }

        if (!(Test-Path $destPath -PathType Container))
        {
            New-Item -ItemType Directory -Force -Path $destPath
        }

        Add-Type -AssemblyName System.Drawing

        $srcImg = [System.Drawing.Image]::FromFile($sourcePath)
     
        $bmpFile = new-object System.Drawing.Bitmap([int]($srcImg.width)),([int]($srcImg.height))
        
        $Image = [System.Drawing.Graphics]::FromImage($bmpFile)
        $Image.SmoothingMode = "AntiAlias"
        $Image.DrawImage($srcImg, 0, 0)

        if ($Description -ne $null) {
            $fontName = "Verdana"
            $fontSize = 24
            $fontLocationX = 50
            $fontLocationY = 50

            $Font = New-object System.Drawing.Font($fontName, $fontSize)
            $Brush = New-Object Drawing.SolidBrush ([System.Drawing.Color]::FromArgb(255, 0, 255, 0))
            $Image.DrawString($Description, $Font, $Brush, $fontLocationX, $fontLocationY)
        }
 
        $bmpFile.save($destPath, [System.Drawing.Imaging.ImageFormat]::Jpeg)
    }
    catch [System.IO.FileNotFoundException] {
        Write-Host "Error " $_.Exception.ToString()
    }
    catch [Exception] {
        Write-Host "Exception encountered in AddTextToImage:"
        Write-Host $_.Exception.ToString()
        Write-Host $_.Exception.GetType().FullName
        Write-Host $_.Exception.Message
        Write-Host "Done handling exception."
    }
    finally {
        $bmpFile.Dispose()
        $srcImg.Dispose()
    }
}

Function MainRunner {

    Write-Output "Running the timestamp script..."

    $folder = 'C:\users\R.Cody\Dropbox\ATCS Monitor\Capture\UP-Nampa-Sub'
    $filter = '*.jpg'
    $fsw = New-Object IO.FileSystemWatcher $folder, $filter -Property @{
     IncludeSubdirectories = $false              # <-- set this according to your requirements
     NotifyFilter = [IO.NotifyFilters]'FileName, LastWrite'
    }

    $onCreated = Register-ObjectEvent $fsw Created -SourceIdentifier FileCreated -Action {
        $path = $Event.SourceEventArgs.FullPath
        $name = $Eventa.SourceEventArgs.Name
        $changeType = $Event.SourceEventArgs.ChangeType
        $timeStamp = $Event.TimeGenerated
        Write-Output "The file '$name' was $changeType at $timeStamp"
        Write-Output "Going to call AddTextToImage..."
        global:AddTextToImage $path "C:\users\R.Cody\Dropbox\ATCS Monitor\Capture\UP-Nampa-Sub\modified" "Foo"
        Write-Output "Tried calling AddTextToImage..."
    }

    $counter = 0
    while(!$Host.UI.RawUI.KeyAvailable -and ($counter++ -lt 10))
    {
        Start-Sleep 1
    }

    Unregister-Event -SourceIdentifier FileCreated

    Write-Output "Done running the timestamp script..."
}

MainRunner
