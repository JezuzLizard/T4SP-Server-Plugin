csv_parser = {
    source = path.join(dependencies.basePath, "csv-parser"),
}

function csv_parser.import()
    dependson "csv-parser"
    csv_parser.includes()
end

function csv_parser.includes()
    includedirs {
        csv_parser.source
    }
end

function csv_parser.project()
    
end

table.insert(dependencies, csv_parser)
