import epygram
import matplotlib.pyplot as plt
import numpy as np

def plot_vertical_section(field_name, level_dim, file_path, output_path):
    # Charger les données
    f = epygram.formats.resource.open(file_path)

    # Extraire les données du champ spécifié
    field = f.read_field(field_name)
    levels = f.read_field(level_dim)

    # Extraire les valeurs du champ
    data = field.values
    lons = field.grid.lon.values
    lats = field.grid.lat.values
    z_levels = levels.values

    # Créer la figure et les axes
    fig, ax = plt.subplots(figsize=(10, 8))

    # Tracer la section verticale
    contour = ax.contourf(lons, z_levels, data, cmap='viridis')

    # Ajouter une barre de couleur
    cbar = plt.colorbar(contour, ax=ax)
    cbar.set_label(field_name)

    # Ajouter des labels et un titre
    ax.set_xlabel('Longitude')
    ax.set_ylabel('Niveau vertical')
    ax.set_title(f'Section verticale de {field_name}')

    # Sauvegarder la figure
    plt.savefig(output_path)
    plt.close(fig)

# Exemple d'utilisation
file_path = 'path/to/your/datafile.arn'  # Remplacez par le chemin de votre fichier de données
output_path = 'vertical_section.png'     # Chemin de sortie pour l'image
field_name = 'T'                          # Nom du champ à tracer (par exemple, température)
level_dim = 'lev'                         # Nom de la dimension des niveaux verticaux

plot_vertical_section(field_name, level_dim, file_path, output_path)