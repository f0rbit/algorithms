function removeSubfolders(folder: string[]): string[] {
    folder.sort();

    const result: string[] = [];
    result[0] = folder[0];

    for (var i = 1; i < folder.length; i++) {
        const last_folder = result[result.length - 1] + "/";
        if (folder[i].startsWith(last_folder)) continue;
        result.push(folder[i]);
    }

    return result;
};
