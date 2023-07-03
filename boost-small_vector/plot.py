import pygal
import os
import csv

# plot
with open('./result.csv') as csvfile:
    #line_chart = pygal.Line(logarithmic=True)
    line_chart = pygal.Line()
    line_chart.title = 'emplace_back time'
    line_chart.x_labels = []
    for i in range(1,256):
        line_chart.x_labels += [str(i*2)]

    experiments = {}

    reader = csv.DictReader(csvfile)
    for row in reader:
        #if row['Group'] == 'size_2':
        if row['Group'] == 'const_16':
            experiment_name = row['Experiment']
            if experiment_name not in experiments:
                experiments[experiment_name] = []
            experiments[experiment_name].append(float(row['Baseline']))

    for experiment_name in experiments:
        line_chart.add(experiment_name, experiments[experiment_name])

    line_chart.render_to_file('./small_vector.svg')